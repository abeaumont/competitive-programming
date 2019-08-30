// https://codeforces.com/contest/1208/problem/E
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;
using ii = tuple<int, int>;
using q = deque<ii>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k, l, n, w, x;
  cin >> n >> w;
  vi a(w), b(w);
  for (int i = 0; i < n; i++) {
    cin >> l;
    k = w - l;
    if (l >= k) {
      q q;
      q.push_back({0, -1});
      for (int j = 0; j < w; j++) {
        if (j <= l) {
          if (j == l ) x = 0;
          else cin >> x;
          while (!q.empty() && x > get<0>(q.back()))
            q.pop_back();
          q.push_back({x, j});
        }
        while (!q.empty() && get<1>(q.front()) < j - k)
          q.pop_front();
        int d = get<0>(q.front());
        a[j] += d;
        if (j < w - 1) a[j + 1] -= d;
      }
    } else {
      ll m = 0;
      for (int j = 0; j < l; j++) {
        cin >> b[j];
        m = max(m, b[j]);
        a[j] += m;
        a[j + 1] -= m;
      }
      a[l] += m;
      a[w - l] -= m;
      m = 0;
      for (int j = 0; j < l; j++) {
        m = max(m, b[l - j - 1]);
        a[w - j - 1] += m;
        if (j) a[w - j] -= m;
      }
    }
  }
  for (int i = 0; i < w; i++) {
    if (i) a[i] += a[i - 1];
    cout << a[i] << " \n"[i == w - 1];
  }
}
