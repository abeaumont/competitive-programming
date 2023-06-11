// https://open.kattis.com/problems/courseplanning
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  map<string, ll> m;
  for (int i = 0; i < n; i++) {
    string s;
    ll x;
    cin >> s >> x;
    m[s] = x;
  }
  vector<ll> a;
  vector<pair<ll, ll>> b;
  for (auto it = m.begin(); it != m.end(); it++) {
    if (it->first.back() == '1') {
      ll x = it->second;
      it++;
      if (it->second < x) b.push_back({x, it->second});
      else {
        a.push_back(x);
        a.push_back(it->second);
      }
    } else if (it->first.back() != '2')
      a.push_back(it->second);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.first + a.second < b.first + b.second;
  });
  vector<ll> psum(a.size() + 1);
  for (int i = 0; i < a.size(); i++) psum[i + 1] = psum[i] + a[i];

  vector<ll> mn(b.size());
  for (int i = b.size() - 1; i >= 0; i--) {
    mn[i] = b[i].first;
    if (i < b.size() - 1) mn[i] = min(mn[i], mn[i + 1]);
  }

  vector<ll> qsum(b.size() * 2 + 1);
  ll sum = 0, mx = 0;
  for (int i = 0; i < b.size(); i++) {
    qsum[i * 2 + 1] = sum + mn[i];
    mx = max(mx, b[i].second);
    sum += b[i].first + b[i].second;
    qsum[i * 2 + 1] = min(qsum[i * 2 + 1], sum - mx);
    qsum[i * 2 + 2] = sum;
  }

  ll best = 1000000000000000000LL;
  for (int i = max(0, k - int(a.size())); i <= min(k, int(b.size() * 2)); i++)
    best = min(best, psum[k - i] + qsum[i]);
  cout << best << '\n';
}
