#include "stdc++.h"
#include <regex>

#define vec vector
using namespace std;

int main() {
  ifstream file { "./3in.txt" };
  string s((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
  string::const_iterator text_iter = s.cbegin();

  regex muls("mul\\((\\d{1,3}),(\\d{1,3})\\)");
  regex dos("do\\(\\)");
  regex donts("don't\\(\\)");

  vec<int> do_indexes = {};
  vec<int> dont_indexes = {};

  smatch matches;
  int seen = 0;
  while (regex_search(text_iter, s.cend(), matches, dos)) {
    do_indexes.push_back(seen + matches.position());
    seen += matches.position() + 4;
    text_iter = matches.suffix().first;
  }
  seen = 0;
  text_iter = s.cbegin();
  while (regex_search(text_iter, s.cend(), matches, donts)) {
    dont_indexes.push_back(seen + matches.position());
    seen += matches.position() + 7;
    text_iter = matches.suffix().first;
  }
  text_iter = s.cbegin();

  long sum = 0;
  bool enabled = true;
  seen = 0;
  while (regex_search(text_iter, s.cend(), matches, muls)) {
    int last_do = -1, last_dont = -1;
    
    seen += matches.position() + matches.length();
    
    for (int i = 0; i < do_indexes.size(); i++) {
      if (do_indexes[i] < seen) last_do = do_indexes[i];
    }
    for (int i = 0; i < dont_indexes.size(); i++) {
      if (dont_indexes[i] < seen) last_dont = dont_indexes[i];
    }
    enabled = last_do >= last_dont;

    sum += enabled ? stoi(matches[1].str()) * stoi(matches[2].str()) : 0; 
    text_iter = matches.suffix().first;
  }
  cout << sum;
  return 0;
}