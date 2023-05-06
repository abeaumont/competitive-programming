// https://www.aceptaelreto.com/problem/statement.php?id=105
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string days[6] = {"MARTES",  "MIERCOLES", "JUEVES",
                    "VIERNES", "SABADO",    "DOMINGO"};
  while (1) {
    double x;
    cin >> x;
    if (x < 0) break;
    double mx = x, mn = x, sum = x;
    bool mxdup = 0, mndup = 0;
    string mxs = days[0], mns = days[0];
    for (int i = 1; i < 6; i++) {
      cin >> x;
      sum += x;
      if (x == mx) mxdup = 1;
      else if (x > mx)
        mx = x, mxdup = 0, mxs = days[i];
      if (x == mn) mndup = 1;
      else if (x < mn)
        mn = x, mndup = 0, mns = days[i];
    }
    cout << (mxdup ? "EMPATE" : mxs) << ' ' << (mndup ? "EMPATE" : mns) << ' '
         << (x > sum / 6 ? "SI\n" : "NO\n");
  }
}
