// https://codeforces.com/contest/1038/problem/D
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll x, s = 0, m = 2000000000LL;
  if (n == 1) { cin >> x; cout << x << endl; return 0; }
  bool pos = false, neg = false;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x >= 0) pos = true;
    if (x <= 0) neg = true;
    x = abs(x);
    m = min(m, 2*x);
    s += x;
  }
  if (!pos || !neg) s-= m;
  cout << s << endl;
}
