#include "stdc++.h"

#define vec vector
using namespace std;

int main() {
  ifstream file { "./6in.txt" };
  string s;
  vec<vec<char>> inp = {};
  while(getline(file, s)) {
    vec<char> line = {};
    for (int i = 0; i < s.length(); i++) {
      line.push_back(s[i]);
    }
    inp.push_back(line);
  }

  vec<pair<int, int>> dirs = { 
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1),
    make_pair(-1, 0),
  };

  int dir_index = 0;
  map<pair<int, int>, set<int>> dir_at_loc;

  int opx = 0, opy = 0;
  int px = 0, py = 0;
  int c = 0;
  for (int y = 0; y < inp.size(); y++) {
    for (int x = 0; x < inp[y].size(); x++) {
      if (inp[y][x] == '^') {
        opx = px = x;
        opy = py = y;
        inp[y][x] = '.';
        dir_at_loc[make_pair(x, y)] = { 0 };
      }
    }
  }

  for (int bx = 0; bx < inp[0].size(); bx++) {
    for (int by = 0; by < inp.size(); by++) {
      // Try add blockade at [bx,by]
      if (inp[by][bx] != '.') continue;
      inp[by][bx] = '#';

      px = opx;
      py = opy;
      dir_index = 0;
      dir_at_loc[make_pair(px, py)] = { 0 };

      while (true) { 
        int tx = px + dirs[dir_index].first, ty = py + dirs[dir_index].second;
        if (tx < 0 || tx >= inp[0].size() || ty < 0 || ty >= inp.size()) break;

        if (inp[ty][tx] == '#') {
          dir_index = (dir_index + 1) % 4;
          continue;
        }

        auto p = make_pair(tx, ty);
        if (dir_at_loc.count(p) && dir_at_loc[p].count(dir_index)) {
          // loop found, break
          c++;
          break;
        }
        
        if (inp[ty][tx] == '.' || inp[ty][tx] == 'X') {
          if (dir_at_loc.count(p)) dir_at_loc[p].insert(dir_index);
          else dir_at_loc[p] = { dir_index };
        }

        px = tx;
        py = ty;
      }

      // reset original
      inp[by][bx] = '.'; 
      dir_at_loc.clear();
    }
  }
  
  cout << c;
  return 0;
}