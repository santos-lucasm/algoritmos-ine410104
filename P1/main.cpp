#include <cmath>
#include <iostream>
#include <vector>

std::vector<int> buildVector(int matr) {
  std::vector<int> a = std::vector<int>(15);
  for (int i = 0; i <= (matr - 1); i++) {
    a[i] = i;
  }
  for (int i = 0; i <= (14 - matr); i++) {
    a[matr + i] = matr;
  }
  return a;
}

int procedure(std::vector<int> a, int antes, int depois, int matr) {
  int n = depois - antes + 1;
  if (a[depois] < matr) {
    std::cout << 0 << std::endl;
    return 0;
  }
  if (a[antes] == matr) {
    std::cout << n << std::endl;
    return n;
  }
  int meio = floor((antes + depois) / 2);
  int aux =
      procedure(a, antes, meio, matr) + procedure(a, meio + 1, depois, matr);
  std::cout << aux << std::endl;
  return aux;
}

int main() {
  procedure(buildVector(5), 0, 14, 5);
  return 0;
}
