// https://cses.fi/problemset/task/1736
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
  ll z0;
  ll z1;
  ll sum;
};

vector<node> t;
ll k = 1;

void push(ll x, ll y, ll k) {
  ll d = (x+y)/2;
  t[2*k].z1 += t[k].z1;
  t[2*k].z0 += t[k].z0;
  t[2*k].sum += t[k].z1 * (d-x)*(d-x+1)/2 + t[k].z0 * (d-x+1);
  t[2*k+1].z1 += t[k].z1;
  ll dz0 = t[k].z0 + (d-x+1) * t[k].z1;
  t[2*k+1].z0 += dz0;
  t[2*k+1].sum += t[k].z1 * (y-d-1)*(y-d)/2 + dz0 * (y-d);
  t[k].z0 = t[k].z1 = 0;
}

void inc(ll a, ll b, ll k, ll x, ll y) {
  if (b < x || y < a) return;
  if (a <= x && y <= b) {
    ll dz0 = x-a+1;
    t[k].z1++;
    t[k].z0 += dz0;
    t[k].sum += (y-x)*(y-x+1)/2 + dz0 * (y-x+1);
    return;
  }
  push(x, y, k);
  ll d = (x+y)/2;
  inc(a, b, k*2, x, d);
  inc(a, b, k*2+1, d+1, y);
  t[k].sum = t[2*k].sum + t[2*k+1].sum;
}
void inc(ll a, ll b) { inc(a, b, 1, 0, k - 1); }

ll sum(ll a, ll b, ll k, ll x, ll y) {
  if (b < x || y < a) return 0;
  if (a <= x && y <= b) return t[k].sum;
  push(x, y, k);
  ll d = (x+y)/2;
  return sum(a, b, 2*k, x, d) + sum(a, b, 2*k+1, d+1, y);
}
ll sum(ll a, ll b) { return sum(a, b, 1, 0, k - 1); }

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll n, q;
  cin >> n >> q;
  while (k < n) k *= 2;
  t = vector<node>(2*k);
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    t[k+i].sum = x;
  }
  for (ll i = k - 1; i > 0; i--) t[i].sum = t[2*i].sum + t[2*i+1].sum;
  while (q--) {
    ll t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    if (t == 1) inc(a, b);
    else cout << sum(a, b) << '\n';
  }
}
