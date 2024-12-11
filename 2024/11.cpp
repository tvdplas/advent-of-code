#include "stdc++.h"

#define vec vector
#define ll long long
using namespace std;

map<pair<ll, int>, ll> mem;

ll memoized_res(ll inp, int depth_to_go) {
  auto p = make_pair(inp, depth_to_go);
  if (mem.count(p)) {
    return mem[p];
  }

  ll res;
  string inp_s = to_string(inp);

  if (depth_to_go == 0) {
    res = 1;
  }
  else if (inp == 0) {
    res = memoized_res(1, depth_to_go - 1);
  }
  else if (inp_s.length() % 2 == 0) {
    ll num1 = stoll(inp_s.substr(0, inp_s.length() / 2));
    ll num2 = stoll(inp_s.substr(inp_s.length() / 2, inp_s.length() / 2));
    res = memoized_res(num1, depth_to_go - 1) + memoized_res(num2, depth_to_go - 1);
  }
  else {
    res = memoized_res(inp * 2024, depth_to_go - 1);
  }

  mem[p] = res;
  return res;
} 

int main() {
  ifstream file { "./11in.txt" };
  string s;
  vec<ll> inp = {};
  getline(file, s);
  istringstream iss(s);
  while(getline(iss, s, ' ')) {
    inp.push_back(stoll(s));
  }

  vec<pair<int, ll>> eval_later = {};
  ll count1 = 0;
  ll count2 = 0;
  for (auto x : inp) {
    count1 += memoized_res(x, 25); // 25 for part 1
    count2 += memoized_res(x, 75); // 25 for part 1
  }

  cout << "part 1: " << count1 << endl;
  cout << "part 2: " << count2 << endl;
  return 0;
}