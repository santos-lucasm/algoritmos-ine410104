#include "bfs.h"
#include <algorithm>
#include <iostream>
#include <list>

int main() {
  // define comercial centers
  center ca = 0;
  center cb = 1;
  center cc = 2;
  center cd = 3;
  center ce = 4;
  auto centers = std::list{ca, cb, cc, cd, ce};

  // define comercial centers delivery path in between them
  auto center_pairs =
      std::list{std::pair{ca, cb}, std::pair{ca, cc}, std::pair{cb, ce},
                std::pair{cc, ca}, std::pair{cc, cd}, std::pair{cd, cb},
                std::pair{cd, ce}};

  auto path = min_path(centers, center_pairs, ca, cc);

  // just printout the path data output
  for (auto center : path) {
    if (center == *path.begin()) {
      std::cout << center;
      continue;
    }
    std::cout << " -> " << center;
  }
  std::cout << std::endl;

  return 0;
}
