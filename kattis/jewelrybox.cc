// https://open.kattis.com/problems/jewelrybox
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    double x, y, hmin, hmax, a, b, va, vb;
    cin >> x >> y;
    hmin = 0, hmax = min(x, y)/2;
    a = (2*hmin+hmax)/3;
    b = (hmin+2*hmax)/3;
    while (b-a > 1e-9) {
      va = (x-2*a)*(y-2*a)*a;
      vb = (x-2*b)*(y-2*b)*b;
      if (vb > va) hmin = a;
      else hmax = b;
      a = (2*hmin+hmax)/3;
      b = (hmin+2*hmax)/3;
    }
    cout << setprecision(10) << va << '\n';
  }
}
