#include <iostream>
#include <tuple>
#include <vector>
#include "z3++.h"

using namespace std;
using namespace z3;
using iiii=tuple<int, int, int, int>;
using viiii=vector<iiii>;

int main() {
  viiii ps;
  int x, y, z, r;
  while (scanf("pos=<%d,%d,%d>, r=%d\n", &x, &y, &z, &r) != -1)
    ps.push_back({x, y, z, r});
  context c;
  expr X = c.int_const("x"), Y = c.int_const("y"), Z = c.int_const("z");
  optimize o(c);
  expr_vector xs(c);
  for (iiii &p : ps) {
    tie(x, y, z, r) = p;
    xs.push_back(ite(abs(X - x) + abs(Y - y) + abs(Z - z) <= r, c.int_val(1), c.int_val(0)));
  }
  o.maximize(sum(xs));
  o.check();
  model m = o.get_model();
  cout << m.eval(X + Y + Z) << endl;
}
