// https://open.kattis.com/problems/justaminute
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int n, m = 0, s = 0;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    m += a;
    s += b;
  }
  if (s <= m * 60) cout << "measurement error\n";
  else cout << fixed << setprecision(9) << double(s) / double(m * 60) << endl;
}
