// https://codeforces.com/contest/1175/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) a[i] += a[i-1];
  }
  ll s = a[n-1] * k;
  sort(a.begin(), a.end()-1);
  for (int i = 0; i < k-1; i++) s -= a[i];
  cout << s << endl;
}
