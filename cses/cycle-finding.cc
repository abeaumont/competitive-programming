// https://cses.fi/problemset/task/1197
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> e;
typedef vector<e> ve;
typedef vector<ll> vi;

const ll INF = 100000000000000000LL;

int main() {
  int n, m;
  cin >> n >> m;
  ve e(m);
  for (int i = 0; i < m; i++) {
    ll a, b, c;
    cin >> a >> b >> c;
    e[i] = {a-1, b-1, c};
  }
  vi d(n), p(n);
  for (int i = 0; i < n; i++) d[i] = INF;
  int x;
  for (int i = 0; i < n; i++) {
    x = -1;
    for (auto z:e) {
      ll a, b, c;
      tie(a, b, c) = z;
      if (d[a] + c < d[b]) {
        d[b] = d[a] + c;
        p[b] = a;
        x = b;
      }
    }
  }
  if (x == -1) cout << "NO\n";
  else {
    for (int i = 0; i < n; i++) x = p[x];
    int o = x;
    vi a(1, o);
    do {
      x = p[x];
      a.push_back(x);
    } while (x != o);
    reverse(a.begin(), a.end());
    cout << "YES\n";
    for (int i = 0; i < a.size(); i++) {
      cout << a[i] + 1;
      if (i < a.size() - 1) cout << " ";
    }
    cout << endl;
  }
}
