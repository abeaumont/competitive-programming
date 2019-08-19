// https://cses.fi/problemset/task/1745/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> d(n * 1000 + 1);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int c : a) {
    for (int i = d.size() - 1; i > 0; i--)
      if (d[i])
        d[i + c] = 1;
    d[c] = 1;
  }
  int c = 0;
  for (int i = 0; i < d.size(); i++)
    if (d[i])
      c++;
  cout << c << "\n";
  for (int i = 0; i < d.size(); i++)
    if (d[i])
      cout << i << " ";
  cout << "\n";
}
