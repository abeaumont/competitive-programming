// https://codeforces.com/contest/1228/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

const ll M = 1000000007;

ll pow(ll a, ll b, ll m) {
  ll r = 1, e = a;
  while (b) {
    if (b & 1) (r *= e) %= m;
    (e *= e) %= m;
    b >>= 1;
  }
  return r;
}

int main() {
  int h, w, r, c;
  cin >> h >> w;
  vvi a(h, vi(w));
  for (int i = 0; i < h; ++i) {
    cin >> r;
    int j = 0;
    for (;j < r; j++)
      a[i][j] = 1;
    if (j < w) a[i][j] = 2;
  }
  for (int i = 0; i < w; ++i) {
    cin >> c;
    int j = 0;
    for (;j < c; j++) {
      if (a[j][i] == 2) {
        cout << "0\n";
        return 0;
      }
      a[j][i] = 1;
    }
    if (j < h) {
      if (a[j][i] == 1) {
        cout << "0\n";
        return 0;
      }
      a[j][i] = 2;
    }
  }
  int s = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      s += a[i][j] == 0;
  cout << pow(2, s, M) << "\n";
}
