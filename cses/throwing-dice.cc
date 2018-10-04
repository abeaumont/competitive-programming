// https://cses.fi/problemset/task/1096
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll M = 1000000007;

vvi mul(vvi x, vvi y) {
  vvi r(6, vi(6));
  for (int j = 0; j < 6; j++)
    for (int k = 0; k < 6; k++) {
      for (int l = 0; l < 6; l++) r[j][k] = (r[j][k]+x[j][l]*y[l][k]%M)%M;
    }
  return r;
}

vvi modpow(vvi x, ll n) {
  if (n == 0) {
    vvi r(6, vi(6));
    for (int i = 0; i < 6; i++) r[i][i] = 1;
    return r;
  }
  vvi u = modpow(x, n/2);
  u = mul(u, u);
  if (n%2) u = mul(u, x);
  return u;
}

int main() {
  ll n;
  cin >> n;
  vvi a(6, vi(6));
  for (int i = 0; i < 5; i++) a[i][i+1] = 1;
  for (int i = 0; i < 6; i++) a[5][i] = 1;
  vvi r = modpow(a, n);
  cout << r[5][5] << endl;
}
