#include "stdc++.h"

#define vec vector
using namespace std;

int main() {
  vec<vec<int>> input = {};
  for (int i = 0; i < 1000; i++) {
    input.push_back({});
    string s;
    getline(cin, s);
    istringstream iss(s);
    string i32;
    while (getline(iss, i32, ' ')) {
      input[i].push_back(stoi(i32));
    }
  }

  int safe = 0;
  for (int i = 0; i < input.size(); i++) {
    for (int r = 0; r < input[i].size(); r++) {
      // remove all but rth index
      vec<int> newinp = {};
      for (int ri = 0; ri < input[i].size(); ri++) {
        if (ri == r) continue;
        newinp.push_back(input[i][ri]);
      }

      bool increasing = newinp[0] < newinp[1];
      bool accept = true;
      for (int j = 1; j < newinp.size(); j++) { 
        int diff = newinp[j - 1] - newinp[j];
        if (abs(diff) < 1 || abs(diff) > 3) accept = false;
        if (diff <= 0 && !increasing) accept = false;
        if (diff >= 0 && increasing) accept = false;
      }
      if (accept) {
        safe++;
        break;
      }
    }
  }
  cout << safe;
  return 0;
}