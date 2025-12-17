#include <unordered_map>
#include <map>
#include <iostream>


/*
- This will include code on studying the map / unordered_map

compilation: g++ -std=c++17 unordered_mp.cpp                                          

template<
    class Key,
    class T,
    class Hash = std::hash<Key>,
    class KeyEqual = std::equal_to<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class unordered_map;


*/





class LERP{
    private:
        std::unordered_map<double, double>v2b_;
        std::map<double, double>order_v2b_;
        std::vector<std::pair<double, double>> v2b_vec; 
    public:
        void addV(const std::pair<double, double>& entry){
            //auto it = v2b_.find(entry.first);
            auto [it, inserted] = v2b_.insert(entry);
            auto v2b_iter = it;
            // [it, T/F (bool) ] 
            if(inserted){
                // we inserted
                order_v2b_.insert(entry);
                v2b_vec.push_back(entry);
            }
            else if(v2b_iter->second != entry.second){
               // Existing key, different value
                v2b_iter->second = entry.second;
                order_v2b_[entry.first] = entry.second;
                for (auto& p : v2b_vec) {
                    if (p.first == entry.first) {
                        p.second = entry.second;
                        break;
                    }
                }
            }

        }

        std::pair<double, double> CalcLERP(){

        }


};



int main(){
    std::unordered_map<std::string, std::string> u =
    {
        {"RED", "#FF0000"},
        {"GREEN", "#00FF00"},
        {"BLUE", "#0000FF"}
    };
    // each pair in the map is a std::pair<const Key, Value>
    // This key is const because it cannot be changed
    
    auto print_key_value = [](const auto& k, const auto& v) {
        std::cout << "Key :" << k << " Value : " << v << std::endl;
    };

    for (const std::pair<const std::string, std::string>& entry : u  ){
        print_key_value(entry.first, entry.second);
    }
    std::cout << " other method "<< std::endl;
    u["short"] = "abc";                              // length 3
    u["long"] = "This is a very long string that exceeds 25 characters";  // length > 25

    std::erase_if(u, [](const auto& pair){ return pair.second.length() > 3; });

    
    for (const auto& [key, value] : u)
        print_key_value(key, value);
    
    
    //std::erase_if(u, [](const auto& pair){ return pair.second.length() > 1; });


    return 0;
}