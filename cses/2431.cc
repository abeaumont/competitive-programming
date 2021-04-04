// https://cses.fi/problemset/task/2431
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll start[20];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  for (ll i = 1, p = 9; i < 18; i++, p = p * 10)
    start[i] = start[i - 1] + p * i;
  ll q, k;
  cin >> q;
  while (q--) {
    cin >> k, k--;
    int i = 0;
    while (i < 17 && start[i + 1] <= k) i++;
    ll d = k - start[i];
    ll o = d / (i + 1);
    int m = d % (i + 1);
    ll n = 1;
    for (int j = 0; j < i; j++) n *= 10;
    n += o;
    for (int j = 0; j < i - m; j++) n /= 10;
    cout << n % 10 << endl;
  }
}
