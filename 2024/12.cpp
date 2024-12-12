#include "stdc++.h"

#define vec vector
#define ll long long
using namespace std;

void dfs(int x, int y, set<pair<int, int>> * visited, vec<vec<pair<int, int>>> * regions, vec<vec<char>> * inp) {
  auto p = make_pair(x, y);
  if (visited->count(p)) return;
  visited->insert(p);
  (*regions)[regions->size() - 1].push_back(p);
  
  vec<pair<int, int>> dirs = {
    make_pair(x + 1, y),
    make_pair(x, y + 1),
    make_pair(x - 1, y),
    make_pair(x, y - 1),
  };

  for (auto dir : dirs) {
    if (dir.second >= 0 && dir.second < inp->size() && dir.first >= 0 && dir.first < (*inp)[dir.second].size()) {
      if((*inp)[dir.second][dir.first] != (*inp)[y][x]) continue;
      
      dfs(dir.first, dir.second, visited, regions, inp);
    }
  }
}

int main() {
  ifstream file { "./12in.txt" };
  string s;
  vec<vec<char>> inp = {};
  while(getline(file, s)) {
    vec<char> line = {};
    for (int i = 0; i < s.length(); i++) {
      line.push_back(s[i]);
    }
    inp.push_back(line);
  }

  set<pair<int, int>> visited;
  vec<vec<pair<int, int>>> regions = {};

  for (int y = 0; y < inp.size(); y++) {
    for (int x = 0; x < inp[y].size(); x++) {
      if (visited.count(make_pair(x, y))) continue;
      regions.push_back({});
      dfs(x, y, &visited, &regions, &inp);
    }
  }

  ll count1 = 0;
  ll count2 = 0;
  for (auto region : regions) {
    ll area = region.size();
    ll perimeter = 0;
    ll sides = 0;

    vec<pair<pair<int, int>, int>> fences = {};

    for (auto cell1 : region) {
      vec<bool> has_neighbour = { false, false, false, false }; // right, down, left, up
      for (auto cell2 : region) {
        if (cell1.first + 1 == cell2.first && cell1.second == cell2.second) has_neighbour[0] = true;
        if (cell1.first == cell2.first && cell1.second + 1 == cell2.second) has_neighbour[1] = true;
        if (cell1.first - 1 == cell2.first && cell1.second == cell2.second) has_neighbour[2] = true;
        if (cell1.first == cell2.first && cell1.second - 1 == cell2.second) has_neighbour[3] = true;
      }

      for (int b = 0; b < 4; b++) {
        if (!has_neighbour[b]) {
          perimeter++;
          fences.push_back(make_pair(cell1, b));
        }
      }
    }
    // cout << inp[region[0].second][region[0].first] << ": area: " << area << ", perimeter" << perimeter << endl;
    count1 += area * perimeter;

    vec<pair<int, int>> dirs = {
      make_pair(1, 0),
      make_pair(0, 1),
      make_pair(-1, 0),
      make_pair(0, -1),
    };
    
    // cout << "fences: " << fences.size() << endl;
    for (int i = 0; i < fences.size(); i++) { 
      sides++;
      // remove all other refs to fences in same line
      auto curr = fences[i];
      auto dir = (curr.second + 1) % 4;
      while (true) {
        curr.first = make_pair(curr.first.first + dirs[dir].first, curr.first.second + dirs[dir].second);
        auto f = find(fences.begin(), fences.end(), curr); 
        if (f == fences.end()) break;
        else {
          fences.erase(f);
        }
      }
      curr = fences[i];
      dir = (curr.second + 3) % 4;
      while (true) {
        curr.first = make_pair(curr.first.first + dirs[dir].first, curr.first.second + dirs[dir].second);
        auto f = find(fences.begin(), fences.end(), curr); 
        if (f == fences.end()) break;
        else {
          fences.erase(f);
        }
      }
    }

    // cout << inp[region[0].second][region[0].first] << ": area: " << area << ", sides: " << sides << endl;
    count2 += area * sides; 
  }

  cout << "part 1: " << count1 << endl;
  cout << "part 2: " << count2 << endl;
  return 0;
}