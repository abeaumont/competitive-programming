#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using iiii=tuple<int, int, int, int>;
using viiii=vector<iiii>;

int main() {
  viiii ps;
  iiii m;
  int x, y, z, r;
  while (scanf("pos=<%d,%d,%d>, r=%d\n", &x, &y, &z, &r) != -1) {
    iiii p = {x, y, z, r};
    ps.push_back(p);
    if (get<3>(m) < r) m = p;
  }
  int c = 0;
  for (iiii &p : ps) {
    int x2, y2, z2, r2;
    tie(x, y, z, r) = p;
    tie(x2, y2, z2, r2) = m;
    c += abs(x - x2) + abs(y - y2) + abs(z - z2) <= r2;
  }
  cout << c << endl;
}
