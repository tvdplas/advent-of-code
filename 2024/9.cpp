#include "stdc++.h"

#define vec vector
using namespace std;

int main() {
  ifstream file { "./9in.txt" };
  string s;
  vec<pair<int, bool>> inp = {};
  getline(file, s);
  bool is_file = true;
  for (int i = 0; i < s.length(); i++) {
    int l = stoi(string({s[i]}));
    for (int j = 0; j < l; j++) {
      inp.push_back(make_pair(is_file ? i / 2 : 0, is_file));
    }
    is_file = !is_file;
  }

  vec<pair<int, bool>> inp2(inp);

  int first_free = 0;
  for (int i = inp.size() - 1; i >= 0; i--) { 
    if (inp[first_free].second) { 
      for (int j = first_free; j < inp.size(); j++) {
        if (!inp[j].second) {
          first_free = j;
          break;
        }
      }
    }
    if (first_free >= i) break;

    auto temp = inp[first_free];
    inp[first_free] = inp[i];
    inp[i] = temp;
  }

  long long res;
  for (int i = 0; i < inp.size() && inp[i].second; i++) {
    res += i * inp[i].first;
  }

  cout << "part 1: " << res << endl;

  for (int i = inp2.size() - 1; i >= 0;) {
    if (!inp2[i].second) {
      i--;
      continue;
    }

    int l = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (inp2[j].first == inp2[i].first) l++;
    } 

    // find free block of length l
    int free_index = 0;
    bool found = false;
    while (free_index < inp2.size() && !found) {
      if (inp2[free_index].second) {
        free_index++;
        continue;
      }
      
      bool big_enough = true;
      for (int j = 1; j < l; j++) { 
        if (inp2[free_index + j].second) {
          free_index += j;
          big_enough = false;
        }
      }
      if (!big_enough) continue;

      found = true;
    }

    if (free_index >= i) {
      i -= l;
      continue;
    }

    for (int j = 0; j < l; j++) {
      swap(inp2[i - j], inp2[free_index + j]);
    }
    i -= l;
  }

  long long res2 = 0;
  for (int i = 0; i < inp2.size(); i++) {
    res2 += i * inp2[i].first;
  }
  cout << "part 2: " << res2 << endl;
  return 0;
}