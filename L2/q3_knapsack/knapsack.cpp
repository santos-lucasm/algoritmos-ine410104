#include "knapsack.h"
#include <algorithm>
#include <iostream>

int loadTrucks(std::vector<int> &trucks, std::vector<int> &items,
               std::function<int(int)> w_function,
               std::function<int(int)> v_function, const int cap) {
  int income = 0;
  for (auto truck : trucks) {
    auto matrix = maximizeTruckLoading(items, w_function, v_function, cap);
    std::cout << "Truck: " << truck << std::endl;
    for (auto x : matrix) {
      for (auto y : x) {
        std::cout << y << " ";
      }
      std::cout << std::endl;
    }

    auto loadedItems = retrieveSelectedItems(items, w_function, matrix, cap);

    std::cout << "Truck " << truck << " got " << loadedItems.size()
              << " items! {";
    for (auto item : loadedItems) {
      income += v_function(item);
      std::cout << " " << item;
    }
    std::cout << " }" << std::endl;
  }

  // Remove all delivered items from items argument list
  items.erase(std::remove(items.begin(), items.end(), 0), items.end());
  return income;
}

std::vector<std::vector<int>>
maximizeTruckLoading(std::vector<int> &items,
                     std::function<int(int)> w_function,
                     std::function<int(int)> v_function, const int cap) {
  std::vector<std::vector<int>> mem;
  mem.resize(items.size() + 1, std::vector<int>(cap + 1, 0));

  for (auto item : items) {
    for (auto w = 0; w <= cap; w++) {
      if (item == 0) {
        continue;
      }
      if (w < w_function(item) && item > 0) {
        mem[item][w] = mem[item - 1][w];
      } else {
        mem[item][w] =
            std::max(mem[item - 1][w],
                     v_function(item) + mem[item - 1][w - w_function(item)]);
      }
    }
  }
  return mem;
}

std::vector<int> retrieveSelectedItems(std::vector<int> &items,
                                       std::function<int(int)> w_function,
                                       std::vector<std::vector<int>> mem,
                                       const int cap) {
  std::vector<int> selectedItems;
  int i = items.size();
  int j = cap;
  while (i > 0 && j > 0) {
    if ((mem[i][j] != mem[i - 1][j]) && items[i - 1] != 0) {
      selectedItems.push_back(items[i - 1]);
      j -= w_function(items[i - 1]);
      items[i - 1] = 0;
    }
    i--;
  }
  return selectedItems;
}
