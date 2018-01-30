// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/theatre-830bdbff/
#include <iostream>
#include <set>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> iii;

set<iii> ranges;

void add(ll m, ll a, ll b) {
  auto it = ranges.lower_bound(make_tuple(a, 0, 0));
  while (it != ranges.end()) {
    ll b2, a2, m2;
    tie(b2, a2, m2) = *it;
    if (a2 > b) break;
    if (m > m2) {
      ranges.erase(it);
      if (b2 > b) ranges.insert(make_tuple(b2, b + 1, m2));
    } else {
      a = b2 + 1;
      if (a > b) break;
    }
    it = ranges.lower_bound(make_tuple(a, 0, 0));
  }
  if (a <= b) ranges.insert(make_tuple(b, a, m));
}

int main() {
  ll n, k;
  cin >> n >> k;
  for (ll i = 0; i < n; i++) {
    ll a, b, c, s, m;
    cin >> a >> b >> c;
    s = a + b + c;
    ll m1 = max(a, (max(b, c)));
    ll r1 = k - m1 - 1;
    ll r = r1;
    add(s, 0, r1);
    ll m2 = -1;
    if (a != m1) m2 = a;
    if (b != m1) m2 = max(m2, b);
    if (c != m1) m2 = max(m2, c);
    if (m2 != -1) {
      ll r2 = k - m2 - 1;
      r = r2;
      s = (a + r1 + 1) % k + (b + r1 + 1) % k + (c + r1 + 1) % k;
      add(s - 3 * (r1 + 1), r1 + 1, r2);
      ll m3 = min(a, min(b, c));
      if (m3 != m2) {
        ll r3 = k - m3 - 1;
        s = (a + r2 + 1) % k + (b + r2 + 1) % k + (c + r2 + 1) % k;
        add(s - 3 * (r2 + 1), r2 + 1, r3);
        r = r3;
      }
    }
    if (r < k) {
      s = (a + r + 1) % k + (b + r + 1) % k + (c + r + 1) % k;
      add(s - 3 * (r + 1), r + 1, k - 1);
    }
  }
  ll M = k * 3 + 1;
  ll i = 0;
  for (auto it : ranges) {
    ll b, a, m;
    tie(b, a, m) = it;
    ll v = a * 3 + m;
    if (v < M) {
      M = v;
      i = a;
    }
  }
  cout << M << endl;
}
