// https://www.codechef.com/FEB18/problems/BIAS
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
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
    for (int i = 0; i < m; i++) {
      a[i] = vi(n);
      for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    int M = m + 1;
    int b;
    for (int i = 0; i < m; i++) {
      int inv = 0;
      for (int j = 0; j < n; j++)
        for (int o = j + 1; o < n; o++)
          if (a[i][j] < a[i][o]) inv++;
      if (inv < M) {
        M = inv;
        b = i;
      }
    }
    for (int i = 0; i < m; i++) {
      if (i == b) cout << u[i];
      else cout << l[i];
      if (i < m - 1) cout << " ";
    }
    cout << endl;
  }
}
