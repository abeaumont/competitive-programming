// https://codeforces.com/contest/1148/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll x = c * 2 + min(a, b) * 2;
  if (a > b || b > a) x++;
  cout << x << endl;
}
