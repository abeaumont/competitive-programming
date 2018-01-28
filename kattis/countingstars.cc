// https://open.kattis.com/problems/countingstars
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vb> vvb;

void search(const vvb &v, vvi &w, int i, int j, int c) {
  if (i < 0 || i >= v.size()) return;
  if (j < 0 || j >= v[i].size()) return;
  if (!v[i][j] || w[i][j]) return;
  w[i][j] = c;
  search(v, w, i - 1, j, c);
  search(v, w, i + 1, j, c);
  search(v, w, i, j - 1, c);
  search(v, w, i, j + 1, c);
}

int main() {
  int m, n, k = 1;
  while (cin >> m >> n) {
    vvb v(m);
    vvi w(m);
    for (int i = 0; i < m; i++) {
      v[i] = vb(n, false);
      w[i] = vi(n, 0);
      for (int j = 0; j < n; j++) {
        char c;
        cin >> c;
        if (c == '-') v[i][j] = true;
      }
    }
    int c = 0;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (v[i][j] && !w[i][j]) {
          search(v, w, i, j, ++c);
        }
    cout << "Case " << k++ << ": " << c << endl;
  }
}
