// https://codeforces.com/contest/1148/problem/D
#include <bits/stdc++.h>

using namespace std;

using ii = tuple<int, int>;
using si = stack<int>;
using vii = vector<ii>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  vii a, b;
  int n, x, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x < y) a.push_back({y, i + 1});
    else b.push_back({x, i + 1});
  }
  if (a.size() > b.size())
    sort(a.begin(), a.end(), greater<ii>());
  else {
    sort(b.begin(), b.end());
    swap(a, b);
  }
  cout << a.size() << "\n";
  for (int i = 0; i < a.size(); i++)
    cout << get<1>(a[i]) << " \n"[i == a.size() - 1];
}
