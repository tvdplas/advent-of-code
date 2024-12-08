#include "stdc++.h"
#include <regex>

#define vec vector
using namespace std;

int main() {
  ifstream file { "./4in.txt" };
  vec<string> inp = {};
  string s;
  while (getline(file, s)) inp.push_back(s);

  vec<pair<int, int>> directions = { 
    // make_pair(0, 1), 
    // make_pair(0, -1), 
    // make_pair(1, 0), 
    make_pair(1, 1), 
    make_pair(1, -1), 
    // make_pair(-1, 0), 
    make_pair(-1, 1), 
    make_pair(-1, -1),
  };

  long count = 0;
  map<pair<int, int>, int> xlocs;
  for (auto dir : directions) { 
    for (int startx = 0; startx < inp[0].length(); startx++) {
      for (int starty = 0; starty < inp.size(); starty++) {
        if (startx + 2 * dir.first < 0 || startx + 2 * dir.first >= inp[0].length()) continue;
        if (starty + 2 * dir.second < 0 || starty + 2 * dir.second >= inp.size()) continue;

        // if (
        //   inp[starty + 0 * dir.second][startx + 0 * dir.first] == 'X' &&
        //   inp[starty + 1 * dir.second][startx + 1 * dir.first] == 'M' &&
        //   inp[starty + 2 * dir.second][startx + 2 * dir.first] == 'A' &&
        //   inp[starty + 3 * dir.second][startx + 3 * dir.first] == 'S'
        // ) count++;

        if (
          inp[starty + 0 * dir.second][startx + 0 * dir.first] == 'M' &&
          inp[starty + 1 * dir.second][startx + 1 * dir.first] == 'A' &&
          inp[starty + 2 * dir.second][startx + 2 * dir.first] == 'S' 
        ) {
          auto p = make_pair(starty + 1 * dir.second, startx + 1 * dir.first);
          if (xlocs[p]) xlocs[p]++;
          else xlocs[p] = 1;
        } 
      }
    }
  }

  for (const auto & [key, value] : xlocs)
    if (value > 1) count++;

  cout << count;
  
  return 0;
}