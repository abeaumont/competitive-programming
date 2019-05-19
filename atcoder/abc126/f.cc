// https://atcoder.jp/contests/abc126/tasks/abc126_f
#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll m, k;
  cin >> m >> k;
  ll x = 1;
  for (int i = 0; i < m; i++) x *= 2;
  if (!k) {
    for (int i = 0; i < x; i++)
      cout << i << " " << i << " \n"[i == x - 1];
    return 0;
  }
  if (k >= x) {
    cout << "-1\n";
    return 0;
  }
  ll y = 0;
  for (int i = 0; i < x; i++)
    if (i != k)
      y ^= i;
  if (y != k) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < x; i++)
    if (i != k)
      cout << i << " ";
  cout << k << " ";
  for (int i = x - 1; i >= 0; i--)
    if (i != k)
      cout << i << " ";
  cout << k << "\n";
}
