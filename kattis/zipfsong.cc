// https://open.kattis.com/problems/zipfsong
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<ll, int>> a(n);
  vector<string> b(n);
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x >> b[i];
    a[i] = {-x * (i + 1), i};
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < m; i++)
    cout << b[get<1>(a[i])] << '\n';
}
