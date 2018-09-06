// https://codeforces.com/contest/1038/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll> ii;

const int N = 2*100000;
ii a[N];

int main() {
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[i] = {x, 0};
  }
  for (int i = n; i < 2*n; i++) {
    cin >> x;
    a[i] = {x, 1};
  }
  sort(a, a+2*n, greater<ii>());
  ll d = 0;
  for (int i = 0; i < 2*n; i++) {
    int t = i % 2;
    ll k, p;
    tie(k, p) = a[i];
    if (t == p) {
      if (t == 0) d += k;
      else d -= k;
    }
  }
  cout << d << endl;
}
