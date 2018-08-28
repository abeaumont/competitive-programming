// https://www.codechef.com/AUG18A/problems/KCOMPRES
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

vi tree;
ll n, nn;

void update(ll k, ll v) {
  ll i = k + nn;
  tree[i] = v;
  for (i /= 2; i > 0 ; i /= 2) tree[i] = max(tree[2*i], tree[2*i+1]);
}

ll qmax(ll a, ll b) {
  a += nn; b += nn;
  ll m = 0;
  while (a <= b) {
    if (a % 2) m = max(m, tree[a++]);
    if (!(b % 2)) m = max(m, tree[b--]);
    a /= 2; b /= 2;
  }
  return m;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll s;
    cin >> n >> s;
    vii a(n);
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;
      a[i] = {x, i};
    }
    if (s < n) {
      cout << 0 << endl;
      continue;
    } else if (n == 1) {
      cout << 2 << endl;
      continue;
    }
    sort(a.begin(), a.end());
    auto sum = [&](ll k) {
      nn = 1;
      while (n > nn) nn *= 2;
      tree = vi(2*nn);
      ll i = 0, j = -1, l = -1, v = -1;
      vi ps;
      while (i < n) {
        ll x, y;
        tie(x, y) = a[i];
        if (v == -1) {
          v = x;
          j = max(0LL, y - k);
          l = min(n - 1, y + k);
          ps.push_back(y);
          i++;
        } else if (v == x && y <= l) {
          l = min(n - 1, y + k);
          ps.push_back(y);
          i++;
        }
        else {
          v = qmax(j, l) + 1;
          for (auto z:ps) update(z, v);
          v = -1;
          ps.resize(0);
        }
      }
      v = qmax(j, l) + 1;
      for (auto z:ps) update(z, v);
      ll s = 0;
      for (ll i = nn; i < 2*nn; i++) s += tree[i];
      return s;
    };
    ll k = 0;
    for (ll b = n/2; b >= 1; b /= 2)
      while (k+b <= n && sum(k+b) <= s) k+=b;
    cout << k + 1 << endl;
  }
}
