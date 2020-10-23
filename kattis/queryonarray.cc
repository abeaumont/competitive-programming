// https://open.kattis.com/problems/queryonarray
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll M = 1e9+7;

struct node {
  ll z0;
  ll z1;
  ll z2;
  ll z3;
  ll sum;
};

vector<node> t;
ll k = 1;
ll div2, div4, div6;

void push(ll x, ll y, ll k) {
  ll d = (x+y)/2;
  ll n = d-x, n2 = n*n%M, n3 = n2*n%M, n4 = n3*n%M;
  ll m3 = (n4+2*n3+n2) % M * div4 % M;
  ll m2 = (2*n3+3*n2+n) % M * div6 % M;
  ll m1 = (n2+n) % M * div2 % M;

  (t[2*k].z3 += t[k].z3) %= M;
  (t[2*k].z2 += t[k].z2) %= M;
  (t[2*k].z1 += t[k].z1) %= M;
  (t[2*k].z0 += t[k].z0) %= M;
  (t[2*k].sum += t[k].z3 * m3 % M) %= M;
  (t[2*k].sum += t[k].z2 * m2 % M) %= M;
  (t[2*k].sum += t[k].z1 * m1 % M) %= M;
  (t[2*k].sum += t[k].z0 * (n+1) % M) %= M;

  ll h = d-x+1, h2 = h*h%M, h3 = h2*h%M;
  n = y-d-1, n2 = n*n%M, n3 = n2*n%M, n4 = n3*n%M;
  m3 = (n4+2*n3+n2) % M * div4 % M;
  m2 = (2*n3+3*n2+n) % M * div6 % M;
  m1 = (n2+n) % M * div2 % M;
  ll dz3 = t[k].z3;
  ll dz2 = (t[k].z2 + 3*h*t[k].z3 % M) % M;
  ll dz1 = (t[k].z1 + 2*h*t[k].z2 % M + 3*h2*t[k].z3 % M) % M;
  ll dz0 = (t[k].z0 + h*t[k].z1 % M + h2*t[k].z2 % M + h3*t[k].z3 % M) % M;
  (t[2*k+1].z3 += dz3) %= M;
  (t[2*k+1].z2 += dz2) %= M;
  (t[2*k+1].z1 += dz1) %= M;
  (t[2*k+1].z0 += dz0) %= M;
  (t[2*k+1].sum += dz3 * m3 % M) %= M;
  (t[2*k+1].sum += dz2 * m2 % M) %= M;
  (t[2*k+1].sum += dz1 * m1 % M) %= M;
  (t[2*k+1].sum += dz0 * (n+1) % M) %= M;
  t[k].z0 = t[k].z1 = t[k].z2 = t[k].z3 = 0;
}

void add(ll a, ll b, ll s, ll k, ll x, ll y) {
  if (b < x || y < a) return;
  if (a <= x && y <= b) {
    ll z3 = s, z2 = 6*s, z1 = 11*s, z0 = 6*s;
    ll h = x-a, h2 = h*h%M, h3 = h2*h%M;
    ll n = y-x, n2 = n*n%M, n3 = n2*n%M, n4 = n3*n%M;
    ll m3 = (n4+2*n3+n2) % M * div4 % M;
    ll m2 = (2*n3+3*n2+n) % M * div6 % M;
    ll m1 = (n2+n) % M * div2 % M;
    ll dz3 = z3;
    ll dz2 = (z2 + 3*h*z3%M)%M;
    ll dz1 = (z1 + 2*h*z2%M +3*h2*z3%M)%M;
    ll dz0 = (z0 + h*z1%M + h2*z2%M + h3*z3%M)%M;
    (t[k].z3 += dz3) %= M;
    (t[k].z2 += dz2) %= M;
    (t[k].z1 += dz1) %= M;
    (t[k].z0 += dz0) %= M;
    (t[k].sum += dz3 * m3 % M) %= M;
    (t[k].sum += dz2 * m2 % M) %= M;
    (t[k].sum += dz1 * m1 % M) %= M;
    (t[k].sum += dz0 * (n+1) %M) %= M;
    return;
  }
  push(x, y, k);
  ll d = (x+y)/2;
  add(a, b, s, k*2, x, d);
  add(a, b, s, k*2+1, d+1, y);
  t[k].sum = (t[2*k].sum + t[2*k+1].sum) % M;
}
void inc(ll a, ll b) { add(a, b, 1, 1, 0, k - 1); }
void dec(ll a, ll b) { add(a, b, -1, 1, 0, k - 1); }

ll sum(ll a, ll b, ll k, ll x, ll y) {
  if (b < x || y < a) return 0;
  if (a <= x && y <= b) return t[k].sum;
  push(x, y, k);
  ll d = (x+y)/2;
  return (sum(a, b, 2*k, x, d) + sum(a, b, 2*k+1, d+1, y)) % M;
}
ll sum(ll a, ll b) { return sum(a, b, 1, 0, k - 1); }

ll modinv(ll a, ll b) {
  ll b0 = b, t, q;
  ll x0 = 0, x1 = 1;
  if (b == 1) return 1;
  while (a > 1) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  return x1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  div2 = modinv(2, M);
  div4 = modinv(4, M);
  div6 = modinv(6, M);
  ll n, q;
  cin >> n >> q;
  while (k < n) k *= 2;
  t = vector<node>(2*k);
  for (ll i = k - 1; i > 0; i--) t[i].sum = t[2*i].sum + t[2*i+1].sum;
  while (q--) {
    ll tt, a, b;
    cin >> tt >> a >> b;
    a--, b--;
    if (tt == 1) inc(a, b);
    else if (tt == 2) dec(a, b);
    else {
      ll s = sum(a, b);
      if (s < 0) s += M;
      cout << s << '\n';
    }
  }
}
