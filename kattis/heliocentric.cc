// https://open.kattis.com/problems/heliocentric
#include <iostream>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;

ii coefficients() {
  int s = 0, old_s = 1, t = 1, old_t = 0, r = 365, old_r = 687;
  while (r) {
    int q = old_r / r;
    int tmp = r;
    r = old_r - q * r;
    old_r = tmp;
    tmp = s;
    s = old_s- q * s;
    old_s = tmp;
    tmp = t;
    t = old_t - q * t;
    old_t = tmp;
  }
  return make_tuple(old_s, old_t);
}

int main() {
  int m1, m2;
  tie(m1, m2) = coefficients();
  int a, b;
  int i = 1;
  while (cin >> a >> b) {
    a = (365 - a) % 365;
    b = (687 - b) % 687;
    int x = (b * 365 * m2 + a * 687 * m1) % (365 * 687);
    if (x < 0) x+= 365 * 687;
    cout << "Case " << i++ << ": " << x << endl;
  }
}
