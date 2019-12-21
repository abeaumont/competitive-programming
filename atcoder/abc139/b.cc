// https://atcoder.jp/contests/abc139/tasks/abc139_b
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<ll>;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int a, b, c = 1, i = 0;
  cin >> a >> b;
  for (; c < b; i++) c += (a - 1);
  cout << i <<"\n";
}
