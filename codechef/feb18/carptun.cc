// https://www.codechef.com/FEB18/problems/CARPTUN
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, a, x, c, d, s;
    cin >> n >> a;
    for (int i = 1; i < n; i++) {
      cin >> x;
      a = max(a, x);
    }
    cin >> c >> d >> s;
    cout << (c - 1) * a << endl;
  }
}
