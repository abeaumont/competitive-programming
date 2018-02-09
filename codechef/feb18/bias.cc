// https://www.codechef.com/FEB18/problems/BIAS
#include <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vi l(m), u(m);
    for (int i = 0; i < m; i++) cin >> l[i] >> u[i];
    vvi a(n);
    for (int i = 0; i < n; i++) {
      a[i] = vi(m);
      for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    vii invs(m);
    for (int i = 0; i < m; i++) {
      int inv = 0;
      for (int j = 0; j < n; j++)
        for (int o = j + 1; o < n; o++)
          if (a[j][i] < a[o][i]) inv++;
      invs[i] = make_tuple(inv, i);
    }
    sort(invs.begin(), invs.end());
    vi r(m);
    for (int i = 0; i < m; i++) {
      int k = get<1>(invs[i]);
      r[k] = u[k] - round(double(u[k] - l[k]) * double(i) / (m - 1));
    }
    for (int i = 0; i < m; i++) {
      cout << r[i];
      if (i < m - 1) cout << " ";
    }
    cout << endl;
  }
}
