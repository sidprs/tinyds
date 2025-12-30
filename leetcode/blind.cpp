
#include "blind.h"

#include <cstdio>
#include <vector>

bool ArrayHash::ValidSudoku(std::vector<std::vector<char>>& input) {
  // mod the grid by
  //

  std::unordered_set<char> rows;
  std::unordered_set<char> cols;
  std::map<std::pair<int, int>, std::unordered_set<char>> square;

  // printf("rows %d", rows);
  // printf("cols %d", cols);

  std::pair<int, int> sq;
  for (int i{}; i < 9; i++) {
    for (int j{}; j < 9; j++) {
      if (input[i][j] == 'i') continue;

      sq = {i / 3, j / 3};
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  std::cout << "blind" << std::endl;
  ArrayHash h;
  using board = std::vector<std::vector<char>>;
}
