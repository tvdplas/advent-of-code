#include "stdc++.h"

#define vec vector
using namespace std;

int main() {
  ifstream file { "./8in.txt" };
  string s;
  vec<vec<char>> inp = {};
  while(getline(file, s)) {
    vec<char> line = {};
    for (int i = 0; i < s.length(); i++) {
      line.push_back(s[i]);
    }
    inp.push_back(line);
  }

  map<char, vec<pair<int, int>>> ant_locs;
  for (int y = 0; y < inp.size(); y++) {
    for (int x = 0; x < inp[y].size(); x++) {
      char c = inp[y][x];
      if (c == '.') continue;

      if (ant_locs.count(c)) ant_locs[c].push_back(make_pair(x, y));
      else ant_locs[c] = { make_pair(x, y) };
    } 
  }
  
  set<pair<int, int>> anti;
  for (const auto & [_, locs] : ant_locs) {
    for (int i = 0; i < locs.size(); i++) {
      for (int j = i + 1; j < locs.size(); j++) {
        auto pi = locs[i], pj = locs[j];
        if (pi.first > pj.first || (pi.first == pj.first && pi.second > pj.second)) {
          swap(pi, pj);
        }
        auto dx = pj.first - pi.first;
        auto dy = pj.second - pi.second;

        auto t1 = make_pair(pi.first - dx, pi.second - dy);
        while (t1.first >= 0 && t1.first < inp[0].size() && t1.second >= 0 && t1.second < inp.size()) {
          anti.insert(t1);
          t1 = make_pair(t1.first - dx, t1.second - dy);
        }
        
        auto t2 = make_pair(pj.first + dx, pj.second + dy);
        while (t2.first >= 0 && t2.first < inp[0].size() && t2.second >= 0 && t2.second < inp.size()) {
          anti.insert(t2);
          t2 = make_pair(t2.first + dx, t2.second + dy);
        }
      }
    }
  }

  //part 2
  for (const auto & [_, locs] : ant_locs)
    for (auto loc : locs) 
      anti.insert(loc);

  cout << anti.size() << endl;

  for (auto p : anti) {
    inp[p.second][p.first] = '#';
  }

  for (int y = 0; y < inp.size(); y++) {
    for (int x = 0; x < inp[y].size(); x++) {
      cout << inp[y][x];
    }
    cout << endl;
  }
  return 0;
}