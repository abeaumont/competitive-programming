// https://codeforces.com/contest/1208/problem/B
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using mii = unordered_map<int, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n;
  vvi a(2000);
  mii c;
  int k = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (!c.count(x)) c[x] = k++;
    a[c[x]].push_back(i);
  }
  vi r(2000);
  for (int i = 0; i < 2000; i++) {
    if (a[i].size() >= 2) {
      int l1 = a[i][1], r1 = a[i].back();
      int l2 = a[i][0], r2 = a[i][a[i].size() - 2];
      for (int j = 0; j < 2000; j++)
        if (l1 < j && l2 < j) r[j] = 2e5;
        else if (l1 < j) r[j] = max(r[j], r2 - j + 1);
        else if (l2 < j) r[j] = max(r[j], r1 - j + 1);
        else r[j] = max(r[j], min(r1, r2) - j + 1);
    }
  }
  int m = 2e5;
  for (int i = 0; i < 2000; i++) m = min(m, r[i]);
  cout << m << "\n";
}
