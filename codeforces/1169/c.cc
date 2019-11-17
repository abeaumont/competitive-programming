// https://codeforces.com/contest/1169/problem/C
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int n, m;
vi a;

bool solve(int k) {
  int x = a[0];
  if (x + k >= m) x = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] <= x && a[i] + k >= x) continue;
    if (a[i] > x && a[i] + k >= m && (a[i] + k) % m >= x) continue;
    if (a[i] > x) x = a[i];
    else return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  a = vi(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (solve(0)) {
    cout << "0\n";
    return 0;
  }
  int k = 0;
  for(int b = m/2; b >= 1; b /= 2)
    while(k + b <= m) {
      if (solve(k + b)) break;
      k += b;
    }
  cout << k + 1 << endl;
}
