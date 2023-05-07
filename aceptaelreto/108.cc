// https://www.aceptaelreto.com/problem/statement.php?id=108
#include <bits/stdc++.h>

using namespace std;
double xs[5];
int ys[5];
string cats[5] = {"COMIDAS", "COPAS", "DESAYUNOS", "CENAS", "MERIENDAS"};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  while (getline(cin, s)) {
    if (s.empty()) break;
    stringstream in(s);
    char c;
    double x;
    in >> c >> x;
    if (c == 'A') xs[0] += x, ys[0]++;
    else if (c == 'C')
      xs[1] += x, ys[1]++;
    else if (c == 'D')
      xs[2] += x, ys[2]++;
    else if (c == 'I')
      xs[3] += x, ys[3]++;
    else if (c == 'M')
      xs[4] += x, ys[4]++;
    else {
      double mx = xs[0], mn = xs[0], sum = xs[0];
      int mxi = 0, mni = 0, count = ys[0];
      bool mxd = 0, mnd = 0;
      for (int i = 1; i < 5; i++) {
        sum += xs[i];
        count += ys[i];
        if (xs[i] > mx) mx = xs[i], mxi = i, mxd = 0;
        else if (xs[i] == mx)
          mxd = 1;
        if (xs[i] < mn) mn = xs[i], mni = i, mnd = 0;
        else if (xs[i] == mn)
          mnd = 1;
      }
      cout << (mxd ? "EMPATE" : cats[mxi]) << '#'
           << (mnd ? "EMPATE" : cats[mni]) << '#'
           << (xs[0] * count > sum * ys[0] ? "SI" : "NO") << '\n';
      fill(xs, xs + 5, 0);
      fill(ys, ys + 5, 0);
    }
  }
}
