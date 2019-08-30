// https://cses.fi/problemset/task/1193/
#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<iii> q;

int main() {
  int n, m;
  cin >> n >> m;
  vvc a(n);
  vvi b(n);
  int ai, aj, bi, bj;
  for (int i = 0; i < n; i++) {
    a[i] = vc(m);
    b[i] = vi(m, -1);
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        ai = i; aj = j;
      } else if (a[i][j] == 'B') {
        bi = i; bj = j;
      }
    }
  }
  q q;
  q.push(make_tuple(ai, aj, 0));
  while (!q.empty()) {
    int i, j, k;
    tie(i, j, k) = q.front();
    q.pop();
    if (b[i][j] != -1) continue;
    b[i][j] = k;
    if (i == bi && j == bj) {
      cout << "YES\n" << b[i][j] << endl;
      string p;
      while (i != ai || j != aj) {
        if (i > 0 && b[i - 1][j] == k - 1) {
          p.push_back('D');
          i--;
        } else if (i < n - 1 && b[i + 1][j] == k - 1) {
          p.push_back('U');
          i++;
        } else if (j > 0 && b[i][j - 1] == k - 1) {
          p.push_back('R');
          j--;
        } else {
          p.push_back('L');
          j++;
        }
        k--;
      }
      reverse(p.begin(), p.end());
      cout << p << endl;
      return 0;
    }
    if (i > 0 && a[i - 1][j] != '#' && b[i - 1][j] == -1)
      q.push(make_tuple(i - 1, j, k + 1));
    if (i < n - 1 && a[i + 1][j] != '#' && b[i + 1][j] == -1)
      q.push(make_tuple(i + 1, j, k + 1));
    if (j > 0 && a[i][j - 1] != '#' && b[i][j - 1] == -1)
      q.push(make_tuple(i, j - 1, k + 1));
    if (j < m - 1 && a[i][j + 1] != '#' && b[i][j + 1] == -1)
      q.push(make_tuple(i, j + 1, k + 1));
  }
  cout << "NO\n";
}
