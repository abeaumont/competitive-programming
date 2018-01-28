// https://open.kattis.com/problems/tutorial
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  long long m, n, t;
  cin >> m >> n >> t;
  long long p = 1;
  bool tle = false;
  switch (t) {
  case 1:
    for (int i = 1; i <= n; i++) {
      p *= i;
      if (p > m) {
        tle = true;
        break;
      }
    }
    cout << (tle ? "TLE\n" : "AC\n");
    break;
  case 2:
    if (n > log2(m)) cout << "TLE\n";
    else cout << "AC\n";
    break;
  case 3:
    if (n > m || n * n > m || n * n * n > m || n * n * n * n > m) cout << "TLE\n";
    else cout << "AC\n";
    break;
  case 4:
    if (n > m || n * n > m || n * n * n > m) cout << "TLE\n";
    else cout << "AC\n";
    break;
  case 5:
    if (n * n > m) cout << "TLE\n";
    else cout << "AC\n";
    break;
  case 6:
    if (double(n) * log2(double(n)) > m) cout << "TLE\n";
    else cout << "AC\n";
    break;
  case 7:
    if (n > m) cout << "TLE\n";
    else cout << "AC\n";
  }
}
