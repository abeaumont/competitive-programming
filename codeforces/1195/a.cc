// https://codeforces.com/contest/1195/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, x;
  cin >> n >> k;
  vector<int> a(k);
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x-1]++;
  }
  int s = 0, c = 0;
  for (int i = 0; i < k; i++) {
    s += a[i] / 2;
    c += a[i] % 2;
  }
  int t = ((n - 1) / 2 + 1);
  t -= s;
  cout << s * 2 + min(c, t) << "\n";
  
}
