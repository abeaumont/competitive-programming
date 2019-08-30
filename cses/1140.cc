// https://cses.fi/problemset/task/1140/
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> iii;
typedef vector<iii> viii;
typedef vector<ll> vi;

int main() {
  ll n, x, y, z;
  cin >> n;
  viii a(n);
  vi c(n);
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    a[i] = {y, x, z};
  }
  sort(a.begin(), a.end());
  c[0] = get<2>(a[0]);
  for (int i = 1; i < n; i++) {
    tie(y, x, z) = a[i];
    int k = lower_bound(a.begin(), a.end(), make_tuple(x, 0, 0)) - a.begin() - 1;
    ll m = c[i - 1];
    if (k >= 0) m = max(m, c[k] + z);
    else m = max(m, z);
    c[i] = m;
  }
  cout << c[n - 1] << endl;
}
