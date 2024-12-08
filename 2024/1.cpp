#include "stdc++.h"

#define vec vector
using namespace std;

int main() {
  vec<long> v1 = {};
  vec<long> v2 = {};

  for (int i = 0; i < 1000; i++) {
    int i1, i2;
    cin >> i1 >> i2;
    v1.push_back(i1);
    v2.push_back(i2);
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  long diff = 0;
  for (int i = 0; i < 1000; i++) {
    diff += abs(v1[i] - v2[i]);
  }
  cout << diff << endl;

  long sim = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (v1[i] == v2[j]) sim += v1[i];
    }
  }
  cout << sim << endl;
  return 0;
}