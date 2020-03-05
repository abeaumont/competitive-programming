// https://codeforces.com/contest/1316/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using si = set<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, m, p, a, b;
  cin >> n >> m >> p;
  int k = -1, l = -1;
  for (int i=0; i<n; i++) {
    cin >> a;
    if (a%p != 0 && k < 0) k=i;
  }
  for (int j=0; j<m; j++) {
    cin >> b;
    if (b%p != 0 && l < 0) l=j;
  }
  cout << k+l << endl;
}
