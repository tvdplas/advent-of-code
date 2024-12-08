#include "stdc++.h"

#define vec vector
using namespace std;

bool find_target(vec<long long>* vals, int index, long long target, long long current) {
  if (index == (*vals).size()) {
    return target == current;
  }

  int val_length = (int)(log((*vals)[index]) / log(10));
  long long p = pow(10, val_length + 1);
  return find_target(vals, index + 1, target, current + (*vals)[index]) 
      || find_target(vals, index + 1, target, current * (*vals)[index])
      || find_target(vals, index + 1, target, current * p + (*vals)[index]); // part 2
}

int main() {
  ifstream file { "./7in.txt" };
  string s;
  vec<vec<long long>> inp = {};
  while(getline(file, s)) {
    string x;
    istringstream iss(s);
    vec<long long> line = {};
    while(getline(iss, x, ' ')) {
      line.push_back(stoll(x));
    }
    inp.push_back(line);
  }

  long long c = 0;
  for (int l = 0; l < inp.size(); l++) {
    if (find_target(&inp[l], 2, inp[l][0], inp[l][1])) c += inp[l][0];    
  }

  cout << c;

  return 0;
}