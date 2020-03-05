// https://codeforces.com/contest/1305/problem/E
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
  ll n, m;
  cin >> n >> m;
  if (n <= 2) {
    if (m) cout << "-1\n";
    else for (int i = 1; i <= n; i++) cout << i << " \n"[i==n];
    return 0;
  }
  vi r;
  int i = 1, k = 1;
  ll c = 0;
  for (; i <= 2; i++) r.push_back(i);
  for (; i <= n; i++) {
    if (c+k>m) break;
    r.push_back(i);
    c += k;
    if (i%2==0) k++;
  }
  if (i>n && c<m) {
    cout << "-1\n";
    return 0;
  }
  if (c<m) {
    ll d = m-c;
    if (d*2 > r.size()) {
      cout << "-1\n";
      return 0;
    }
    r.push_back(r[i-2]+r[i-d*2-1]);
    i++;
  }
  ll sum = r[i-2]+1;
  ll next = r[i-2] + sum;
  for (; i<=n; i++) {
    if (next > 1000000000) {
      cout << "-1\n";
      return 0;
    }
    r.push_back(next);
    next += sum;
  }
  for (int i = 0; i < n; i++) cout << r[i] << " \n"[i == n-1];
}
