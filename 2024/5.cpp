#include "stdc++.h"
#include <regex>

#define vec vector
using namespace std;

int main() {
  ifstream file { "./5in.txt" };
  string s;
  map<int, set<int>> pred; 
  for (int i = 0; i < 1176; i++) {
    getline(file, s);
    cout << s << endl; 
    int a = stoi(s.substr(0, 2)), b = stoi(s.substr(3, 2));
    if (pred.count(b)) pred[b].insert(a);
    else pred[b] = { a };
  }

  long sum = 0;
  while (getline(file, s)) {
    vec<int> pages = {};
    istringstream iss(s);
    string a;
    while(getline(iss, a, ',')) {
      pages.push_back(stoi(a));
    }

    bool passed = true;
    for (int i = 0; i < pages.size(); i++) {
      for (int j = i + 1; j < pages.size(); j++) {
        int x = pages[i];
        int y = pages[j];
        if (pred[x].count(y)) passed = false;
      }
    }
    if (passed) {
      // sum += pages[pages.size() / 2];
    }
    else {
  	  sort(pages.begin(), pages.end(), [&pred](int x, int y) {
        return pred[x].count(y);
      });
      sum += pages[pages.size() / 2];
    }
  }
  cout << sum;
  return 0;
}