#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int solver(std::string x1, std::string x2, std::string x3) {
  int m = x1.size();
  int n = x2.size();
  int o = x3.size();
  if (m == 0 || n == 0 || o == 0) {
    return 0;
  } else {
    if ((x1[m - 1] == x2[n - 1]) && (x2[n - 1] == x3[o - 1])) {
      x1.resize(m - 1);
      x2.resize(n - 1);
      x3.resize(o - 1);
      return solver(x1, x2, x3) + 1;
    } else {
      std::string aux1 = x1;
      aux1.resize(m - 1);

      std::string aux2 = x2;
      aux2.resize(n - 1);

      std::string aux3 = x3;
      aux3.resize(o - 1);

      int part1 = solver(x1, aux2, aux3);
      int part2 = solver(aux1, x2, aux3);
      int part3 = solver(aux1, aux2, x3);
      return std::max({part1, part2, part3});
    }
  }
}

int solverMem(std::string x1, std::string x2, std::string x3) {
  std::vector<std::vector<std::vector<int>>> mem(
      x1.size(),
      std::vector<std::vector<int>>(x2.size(), std::vector<int>(x3.size(), 0)));

  for (int x = 0; x < x1.size(); x++) {
    for (int y = 0; y < x2.size(); y++) {
      for (int z = 0; z < x3.size(); z++) {
        if (x == 0 || y == 0 || z == 0) {
          continue;
        }
        if (x == y && y == z) {
          mem[x][y][z] = mem[x - 1][y - 1][z - 1] + 1;
        } else {
          mem[x][y][z] = std::max({mem[x][y - 1][z - 1], mem[x - 1][y][z - 1],
                                   mem[x - 1][y - 1][z]});
        }
      }
    }
  }
  std::cout << "xi" << std::endl;
  for (auto x : mem) {
    for (auto y : x) {
      for (auto z : y) {
        std::cout << z << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}

int main() {
  std::string x1 = {'a', 'b', 'z', 'e', 'e', 'c', 'i', 't', 'a', 'e'};
  std::string x2 = {'k', 'w', 'a', 'z', 'w', 'e', 'y', 'i', 't', 'e'};
  std::string x3 = {'a', 'b', 'z', 'e', 'e', 'c', 'i', 't', 'a', 'e'};
  std::cout << solver(x1, x2, x3) << std::endl;
  std::cout << solverMem(x1, x2, x3) << std::endl;
  return 0;
}
