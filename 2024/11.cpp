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

  if (depth_to_go == 0) {
    mem[p] = 1;
    return 1;
  }

  if (inp == 0) {
    auto res = memoized_res(1, depth_to_go - 1);
    mem[p] = res;
    return res;
  }

  string inp_s = to_string(inp);
  if (inp_s.length() % 2 == 0) {
    ll num1 = stoll(inp_s.substr(0, inp_s.length() / 2));
    ll num2 = stoll(inp_s.substr(inp_s.length() / 2, inp_s.length() / 2));
    auto res = memoized_res(num1, depth_to_go - 1) + memoized_res(num2, depth_to_go - 1);
    mem[p] = res;
    return res;
  }

  auto res = memoized_res(inp * 2024, depth_to_go - 1);
  mem[p] = res;
  return res;
} 

int main() {
  ifstream file { "./11in.txt" };
  string s;
  // should be linkedlist
  vec<ll> inp = {};
  getline(file, s);
  istringstream iss(s);
  while(getline(iss, s, ' ')) {
    inp.push_back(stoll(s));
  }

  vec<pair<int, ll>> eval_later = {};
  ll count = 0;
  for (auto x : inp) {
    count += memoized_res(x, 75); // 25 for part 1
  }

  cout << "part 1/2: " << count;
  return 0;
}