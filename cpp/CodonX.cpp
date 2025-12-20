#include <cctype>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <iterator>

// what class of codon it is
namespace FSM {
enum C_TYPE { Invalid, Start, Stop, Amino };
// scanning finite state
enum SCAN_STATE { OUT, IN };
} // namespace FSM " finite state machine "

struct Genome {
  std::string dna_;
  std::string type_; // protein string
};

class FileReader {
public:
  explicit FileReader(const std::string &fname) : filename(fname) {}

  bool readAndFilterFile() {
    std::cout << "[readAndFilterFile]"  << std::endl;
    std::ifstream file(filename);
    if (!file.is_open()) {
      std::cerr << "Error opening file: " << filename << "\n";
      return false;
    }
    sequenceData.clear();
    char ch;
    while (file.get(ch)) {
      unsigned char u = static_cast<unsigned char>(ch);
      if (std::isspace(u))
        continue;
      char upper = static_cast<char>(std::toupper(u));
      if (upper == 'A' || upper == 'T' || upper == 'C' || upper == 'G') {
        sequenceData.push_back(upper);
      }
    }
    return true;
  }

  const std::vector<char> &getSequenceData() const { return sequenceData; }

private:
  std::string filename;
  std::vector<char> sequenceData;
};

class CodonClassifier {
public:
  CodonClassifier() { default_table(); }

  FSM::C_TYPE convert(const std::string &codon) const {
    std::cout << "[FSM::C_TYPE convert]"  << std::endl;
    if (codon.size() != 3)
      return FSM::C_TYPE::Invalid;
    if (codon == "ATG")
      return FSM::C_TYPE::Start;
    if (codon == "TAA" || codon == "TAG" || codon == "TGA")
      return FSM::C_TYPE::Stop;
      // 1 (if the key exists) or 0 (if it does not)
      if (converted_aminos.count(codon)) {
      return FSM::C_TYPE::Amino;
  } else {
      return FSM::C_TYPE::Invalid;
  }

  }

  char CodonTranslate(const std::string &codon) const {
  
    std::cout << "[CodonTranslate]" << std::endl;
    auto it = converted_aminos.find(codon);
    std::cout << "it->second" << std::endl; 
    if (it == converted_aminos.end())
      return '-'; // a end one 
    return it->second;
  }

private:
  std::unordered_map<std::string, char> converted_aminos;

  void default_table() {
    add({"ATT", "ATC", "ATA"}, 'I'); // Isoleucine
    add({"CTT", "CTC", "CTA", "CTG", "TTA", "TTG"}, 'L'); // Leucine
    add({"GTT", "GTC", "GTA", "GTG"}, 'V'); // Valine
    add({"TTT", "TTC"}, 'F'); // Phenylalanine
    add({"ATG"}, 'M'); // Methionine (also start)
    add({"TGT", "TGC"}, 'C'); // Cysteine
    add({"GCT", "GCC", "GCA", "GCG"}, 'A'); // Alanine
    add({"GGT", "GGC", "GGA", "GGG"}, 'G'); // Glycine
    add({"CCT", "CCC", "CCA", "CCG"}, 'P'); // Proline
    add({"ACT", "ACC", "ACA", "ACG"}, 'T'); // Threonine
    add({"TCT", "TCC", "TCA", "TCG", "AGT", "AGC"}, 'S'); // Serine
    add({"TAT", "TAC"}, 'Y'); // Tyrosine
    add({"TGG"}, 'W'); // Tryptophan
    add({"CAA", "CAG"}, 'Q'); // Glutamine
    add({"AAT", "AAC"}, 'N'); // Asparagine
    add({"CAT", "CAC"}, 'H'); // Histidine
    add({"GAA", "GAG"}, 'E'); // Glutamic acid
    add({"GAT", "GAC"}, 'D'); // Aspartic acid
    add({"AAA", "AAG"}, 'K'); // Lysine
    add({"CGT", "CGC", "CGA", "CGG", "AGA", "AGG"}, 'R'); // Arginine
    // stops
    converted_aminos["TAA"] = '|';
    converted_aminos["TAG"] = '|';
    converted_aminos["TGA"] = '|';
  }

  void add(std::initializer_list<const char *> codons, char amino_acid) {
    for (const char *c : codons) {
      converted_aminos[std::string(c)] = amino_acid;
    }
  }

};

class GeneScanner {
public:
  explicit GeneScanner(const CodonClassifier &c) : classifier(c) {}

  std::vector<Genome> scan(const std::string &dna) const {
    std::cout << "[Entered Scan]" << std::endl;
    std::vector<Genome> out;
    // intialize the state to outside , empty protein and start, i = 0
    FSM::SCAN_STATE state = FSM::OUT;
    std::string protein;
    size_t start = 0;
    size_t i = 0;

    while (i + 2 < dna.size()) {
      std::string codon = dna.substr(i, 3);
      FSM::C_TYPE kind = classifier.convert(codon);
      //std::cout << "Kind :" << kind << std::endl;
      if (state == FSM::OUT) {
        // search for ATG by shifting 1
        if (kind == FSM::Start) {
          state = FSM::IN;
          start = i;
          protein.clear();
          i += 3; // move into frame after start
        } else {
          i += 1;
        }
      } else {
        // IN
        if (kind == FSM::Stop) {
          Genome g;
          g.dna_ = dna.substr(start, (i + 3) - start); // include stop
          g.type_ = protein; // excludes start and stop
          out.push_back(std::move(g));
          state = FSM::OUT;
          i += 3; // continue loop after stop
        } else {
          char aa = classifier.CodonTranslate(codon);
          if (aa != '|' && aa != '-')
            protein.push_back(aa);
          i += 3; // keep frame
        }
      }
    }
    return out;
  }

private:
  const CodonClassifier &classifier;
};

class ProteinAggregator {
public:
  void add(const Genome &g) { proteins[g.type_][g.dna_]++; }

  void print(std::ostream &out) const {
    // If no proteins, print nothing (matches "Empty" expected)
    std::cout << "[print / ProteinAggregator]" << std::endl;
      
    if (proteins.empty())
      return;

    std::vector<std::string> protKeys;
    protKeys.reserve(proteins.size());
    for (const auto &kv : proteins)
      protKeys.push_back(kv.first);
    std::sort(protKeys.begin(), protKeys.end());

    for (const auto &prot : protKeys) {
      out << prot << "\n";
      for (const auto &[geneDna, count] : proteins.at(prot)) {
        out << "  " << geneDna << " " << count << "\n"; // two spaces
      }
    }
  }

private:
  std::unordered_map<std::string, std::map<std::string, int>> proteins;
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./protein <file>\n";
    return 1;
  }

  std::string filename = argv[1];
  FileReader reader(filename);

  if (!reader.readAndFilterFile())
    return 1;

  const auto &data = reader.getSequenceData();
  // returns the data all upper case and valid;
  // for(const auto& e : data)
  //   std::cout << e;
  // std::cout << "\n";
  
  std::string dna(data.begin(), data.end());
  // copies data to dna ( const auto -> string )
  CodonClassifier classifier;
  // creates default codon table

  GeneScanner scanner(classifier);
  auto genes = scanner.scan(dna);

  ProteinAggregator agg;
  for (const auto &g : genes)
    agg.add(g);

    agg.print(std::cout);

    return 0;
}
