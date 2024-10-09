#include "knapsack.h"
#include <iostream>
#include <list>

int main() {
  // Algorithm inputs
  std::vector<int> trucks = {1, 2};
  std::vector<int> items = {1, 2, 3, 4, 5, 6};
  auto w_function = [](int item) { return 2 * item; };
  auto v_function = [](int item) { return 3 * item; };
  const int truck_capacity = 20;

  auto income =
      loadTrucks(trucks, items, w_function, v_function, truck_capacity);

  // Display results
  std::cout << "Income: " << income << std::endl
            << "Remaining items to deliver: ";
  for (auto remaining_item : items) {
    std::cout << remaining_item << " ";
  }
  std::cout << std::endl;
  return 0;
}
