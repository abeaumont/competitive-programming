// https://open.kattis.com/problems/estimatingtheareaofacircle
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  while (true) {
    double r;
    int m, c;
    cin >> r >> m >> c;
    if (r == 0 && m == 0 && c == 0) break;
    double a = M_PI * r * r;
    double b = (r * 2) * (r * 2) * double(c) / double(m);
    cout << setprecision(10) << fixed << a << " " << b << endl;
  }
}
