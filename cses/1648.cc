#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int n;
vi t;

void add(int k, ll x) {
  while (k <= n) {
    t[k] += x;
    k += k & -k;
  }
}

ll sum(int k) {
  ll s = 0;
  while (k >= 1) {
    s += t[k];
    k -= k & -k;
  }
  return s;
}

ll sum(int a, int b) {
  return sum(b) - sum(a - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, r, a, b;
  cin >> n >> q;
  vi x(n);
  t = vi(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    add(i + 1, x[i]);
  }
  for (int i = 0; i < q; i++) {
    cin >> r >> a >> b;
    if (r == 1) {
      add(a, b - x[a - 1]);
      x[a - 1] = b;
    }
    else cout << sum(a, b) << "\n";
  }
}
