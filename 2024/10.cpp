#include "stdc++.h"

#define vec vector
using namespace std;

int bfs(int x, int y, set<pair<int, int>> * visited, vec<vec<int>> * inp, bool part2 = false) {
  auto p = make_pair(x, y);
  if (visited->count(p)) return 0; // already been here;
  visited->insert(p);
  auto vcopy(*visited);

  if ((*inp)[y][x] == 9) {
    return 1;
  }

  vec<pair<int, int>> dirs = {
    make_pair(x + 1, y),
    make_pair(x, y + 1),
    make_pair(x - 1, y),
    make_pair(x, y - 1),
  };

  int count = 0;
  for (int i = 0; i < dirs.size(); i++) {
    auto dir = dirs[i];
    if (dir.second >= 0 && dir.second < inp->size() && dir.first >= 0 && dir.first < (*inp)[dir.second].size()) {
      if ((*inp)[dir.second][dir.first] == (*inp)[y][x] + 1) {
        count += bfs(dir.first, dir.second, visited, inp, part2);
        if (part2) {
          *visited = vcopy;
          // cout << "curr: " << x << ", " << y << ". copy reset to: " << endl;
          // for (auto k : *visited) { 
          //   cout << "x: " << k.first << ", y: " << k.second << endl;
          // }
          // cout << "---------------" << endl;
        }
      }
    }
  }
  return count;
}

int main() {
  ifstream file { "./10in.txt" };
  string s;
  vec<vec<int>> inp = {};
  while(getline(file, s)) {
    vec<int> line = {};
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '.') {
        line.push_back(-1);
        continue;
      }
      int x = stoi(string({ s[i] }));
      line.push_back(x);
    }
    inp.push_back(line);
  }

  int count1 = 0;
  int count2 = 0;

  for (int y = 0; y < inp.size(); y++) { 
    for (int x = 0; x < inp[y].size(); x++) {
       if (inp[y][x] == 0) { 
          // start bfs from this point
          set<pair<int, int>> visited1;
          set<pair<int, int>> visited2;
          count1 += bfs(x, y, &visited1, &inp);
          count2 += bfs(x, y, &visited2, &inp, true);
       }
    }
  }

  cout << "part 1: " << count1 << endl;
  cout << "part 2: " << count2 << endl;

  return 0;
}