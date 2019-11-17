// https://codeforces.com/contest/1228/problem/A
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

bool f(int i) {
  vector<int> v(10);
  while (i) {
    int d = i % 10;
    if (v[d]) return false;
    v[d] = 1;
    i /= 10;
  }
  return true;
}

int main() {
  int l, r;
  cin >> l >> r;
  for (int i = l; i <= r; i++)
    if (f(i)) {
      cout << i << "\n";
      return 0;
    }
  cout << "-1\n";
}
