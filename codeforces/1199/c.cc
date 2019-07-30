// https://codeforces.com/contest/1199/problem/C
#include <bits/stdc++.h>

using namespace std;
using mii = map<int, int>;

int main() {
  int n, I, x;
  cin >> n >> I;
  mii m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    m[x]++;
  }
  int k = (8 * I) / n;
  int K = 1;
  for (int i = 0; i < k; i++) {
    K *= 2;
    if (K >= m.size()) {
      cout << 0 << endl;
      return 0;
    }
  }
  int p = m.size();
  vector<int> a;
  for (auto x : m) a.push_back(x.second);
  int M = 1000000000;
  int z = 0;
  for (int i = 0; i < K; i++) z += a[i];
  M = min(M, n - z);
  for (int i = K; i < p; i++) {
    z -= a[i - K];
    z += a[i];
    M = min(M, n - z);
  }
  cout << M << endl;
}
