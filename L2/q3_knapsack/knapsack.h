#pragma once

#include <functional>
#include <vector>

int loadTrucks(std::vector<int> &trucks, std::vector<int> &items,
                std::function<int(int)> w_function,
                std::function<int(int)> v_function, const int cap);

std::vector<std::vector<int>>
maximizeTruckLoading(std::vector<int> &items,
                     std::function<int(int)> w_function,
                     std::function<int(int)> v_function, const int cap);

std::vector<int> retrieveSelectedItems(std::vector<int> &items,
                                       std::function<int(int)> w_function,
                                       std::vector<std::vector<int>> mem,
                                       const int cap);
