// https://arc103.contest.atcoder.jp/tasks/arc103_b
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000;
ll x[N], y[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  ll p = (llabs(x[0])+llabs(y[0]))%2, m = 0;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (p != (llabs(x[i])+llabs(y[i]))%2) {
      ok = false;
      break;
    }
    m = max(m, llabs(x[i]) + llabs(y[i]));
  }
  if (ok) {
    vector<ll> v;
    v.push_back(1);
    if (p==0) v.push_back(1);
    while (v.back()*2 < m+p) v.push_back(v.back()*2);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i];
      if (i < v.size() - 1) cout << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      ll l = x[i], r = y[i];
      string s;
      for (int j = v.size() - 1; j >= 0; j--) {
        if (llabs(l) > llabs(r)) {
          if (l < 0) {
            l += v[j];
            s.push_back('L');
          } else {
            l -= v[j];
            s.push_back('R');
          }
        } else {
          if (r < 0) {
            r += v[j];
            s.push_back('D');
          } else {
            r -= v[j];
            s.push_back('U');
          }
        }
      }
      assert(!l); assert(!r);
      reverse(s.begin(), s.end());
      cout << s << endl;
    }
  } else cout << "-1\n";
}
