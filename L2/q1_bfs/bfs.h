#pragma once

#include <list>
#include <map>

typedef int center;

std::list<center> min_path(std::list<center> &group,
                           std::list<std::pair<center, center>> &relations,
                           center &start, center &destiny);

std::pair<std::map<center, int>, std::map<center, center>>
bfs(std::list<center> &group, std::list<std::pair<center, center>> &relations,
    center &start, center &destiny);
