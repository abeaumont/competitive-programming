// https://codeforces.com/contest/1315/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<ll, ll>;
using vi = vector<ll>;
using si = multiset<ll>;
using vii = vector<ii>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  vi x(n);
  vii a(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) {
    ll y;
    cin >> y;
    a[i] = {x[i], y};
  }
  sort(a.begin(), a.end());
  ll p, t, q, u, sum = 0;
  tie(p, t) = a[0];
  si all;
  all.insert(t);
  ll acc = t;
  for (int i = 1; i < n; i++) {
    tie(q, u) = a[i];
    if (p == q) {
      all.insert(u), acc += u;
    }
    else {
      while (p != q && !all.empty()) {
        auto it = all.end();
        it--;
        acc -= *it;
        all.erase(it);
        sum += acc;
        p++;
      }
      p = q;
      all.insert(u);
      acc += u;
    }
  }
  while (!all.empty()) {
    auto it = all.end();
    it--;
    acc -= *it;
    all.erase(it);
    p++;
    sum += acc;
  }
  cout << sum << '\n';
}
