// https://codingcompetitions.withgoogle.com/codejam/round/0000000000432cc0/000000000043314e
#include <bits/stdc++.h>

using namespace std;

struct node {
  int g, c, c0, c1;
};

using vn = vector<node>;

const int INF = 1e5;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, v, g, c;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    cin >> m >> v;
    vn tree(m + 1);
    for (int i = 1; i <= (m - 1) / 2; i++) {
      cin >> g >> c;
      tree[i] = {g, c, INF, INF};
    }
    for (int i = (m - 1) / 2 + 1; i <= m; i++) {
      cin >> g;
      tree[i] = {0, 0, g ? INF : 0, !g ? INF : 0};
    }
    for (int i = (m - 1) / 2; i > 0; i--) {
      node &n = tree[i];
      node &n1 = tree[i * 2];
      node &n2 = tree[i * 2 + 1];
      int cand0 = INF, cand1 = INF, cor0 = INF, cor1 = INF;
      if (n.g) {
        cand0 = min(n1.c0 + n2.c0, min(n1.c0 + n2.c1, n1.c1 + n2.c0));
        cand1 = n1.c1 + n2.c1;
        if (n.c) {
          cor0 = 1 + n1.c0 + n2.c0;
          cor1 = 1 + min(n1.c1 + n2.c1, min(n1.c0 + n2.c1, n1.c1 + n2.c0));
        }
      } else {
        cor0 = n1.c0 + n2.c0;
        cor1 = min(n1.c1 + n2.c1, min(n1.c0 + n2.c1, n1.c1 + n2.c0));
        if (n.c) {
          cand0 = 1 + min(n1.c0 + n2.c0, min(n1.c0 + n2.c1, n1.c1 + n2.c0));
          cand1 = 1 + n1.c1 + n2.c1;
        }
      }
      n.c0 = min(cand0, cor0);
      n.c1 = min(cand1, cor1);
    }
    cout << "Case #" << t << ": ";
    int r = v ? tree[1].c1 : tree[1].c0;
    if (r < INF) cout << r << '\n';
    else
      cout << "IMPOSSIBLE\n";
  }
}
