// https://cses.fi/problemset/task/1621/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, s = 1;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (int i = 1; i < n; i++)
    if (a[i] != a[i - 1]) s++;
  cout << s << "\n";
}
