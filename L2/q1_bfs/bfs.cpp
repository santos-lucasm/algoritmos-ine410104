#include "bfs.h"
#include <map>
#include <queue>

std::list<center> min_path(std::list<center> &group,
                           std::list<std::pair<center, center>> &relations,
                           center &start, center &destiny) {
  // calculate distance and node father for each center in group
  auto [distance, father] = bfs(group, relations, start, destiny);

  // create path list from bfs returned data
  std::list<center> path;
  auto curr_center = destiny;
  path.push_front(destiny);
  while (father[curr_center] != start) {
    path.push_front(father[curr_center]);
    curr_center = father[curr_center];
  }
  path.push_front(father[curr_center]);

  return path;
}

std::pair<std::map<center, int>, std::map<center, center>>
bfs(std::list<center> &group, std::list<std::pair<center, center>> &relations,
    center &start, center &destiny) {
  std::map<center, bool> visited;
  std::map<center, int> distance;
  std::map<center, center> father;
  for (auto center : group) {
    visited[center] = false;
    distance[center] = -1;
    father[center] = -1;
  }

  // config starting unit
  visited[start] = true;
  distance[start] = 0;
  // preparing to visit queue
  std::queue<center> to_visit;
  to_visit.push(start);

  while (!to_visit.empty()) {
    auto visiting = to_visit.front();
    to_visit.pop();

    for (auto [from, to] : relations) {
      if (from != visiting) {
        continue;
      }

      if (visited[to] == false) {
        visited[to] = true;
        distance[to] = distance[visiting] + 1;
        father[to] = visiting;
        to_visit.push(to);
      }
    }
  }
  return std::make_pair(distance, father);
}
