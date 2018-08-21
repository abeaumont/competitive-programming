// https://www.codechef.com/AUG18A/problems/KCOMPRES
#include <algorithm>
#include <iostream>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
  ll t, n, s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    vi a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];
    if (s < n) {
      cout << 0 << endl;
      continue;
    }
    auto sum = [&](ll k) {
      vvi g(n);
      for (ll i = 0; i < n; i++)
        for (ll j = i + 1; j <= min(n-1, i+k); j++) {
          if (a[i] <= a[j]) g[i].push_back(j);
          if (a[i] >= a[j]) g[j].push_back(i);
        }

      vi p;
      vb v(n);
      function<void(ll)> dfs = [&](ll x) {
        for (ll y:g[x]) {
          if (v[y]) continue;
          v[y] = true;
          dfs(y);
        }
        p.push_back(x);
      };
      for (ll i = 0; i < n; i++)
        if (!v[i]) {
          v[i] = true;
          dfs(i);
        }
      reverse(p.begin(), p.end());

      vi b(n, 1);
      for (ll i = 0; i < p.size(); i++) {
        ll x = p[i];
        for (auto y:g[x]) {
          if (b[x] + (a[x] != a[y]) > b[y]) {
            b[y] = b[x] + (a[x] != a[y]);
            p.push_back(y);
          }
        }
      }
      return accumulate(b.begin(), b.end(), 0);
    };
    ll k = 0;
    for (ll b = n/2; b >= 1; b /= 2)
      while (k+b <= n && sum(k+b) <= s) k+=b;
    cout << k + 1 << endl;
  }
}
