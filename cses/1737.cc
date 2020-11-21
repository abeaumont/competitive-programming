// https://cses.fi/problemset/task/1737
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
  node *l, *r;
  ll sum;
  node(int sum) : sum(sum){};
  node(node *l, node *r) : l(l), r(r), sum(0) {
    if (l) sum += l->sum;
    if (r) sum += r->sum;
  }
};

vector<int> xs;
vector<node *> ts;
int n;

void copy(int k) { ts.push_back(ts[k]); }

node *build(int a, int b) {
  if (a == b) return new node(xs[a]);
  int m = (a + b) / 2;
  return new node(build(a, m), build(m + 1, b));
}

node *update(node *t, int a, int b, int i, int x) {
  if (a == b) return new node(x);
  int m = (a + b) / 2;
  if (i <= m) return new node(update(t->l, a, m, i, x), t->r);
  else
    return new node(t->l, update(t->r, m + 1, b, i, x));
}
void update(int k, int a, int x) { ts[k] = update(ts[k], 0, n - 1, a, x); }

ll sum(node *t, int a, int b, int x, int y) {
  if (x > y) return 0;
  if (a == x && b == y) return t->sum;
  int m = (a + b) / 2;
  return sum(t->l, a, m, x, min(y, m)) + sum(t->r, m + 1, b, max(x, m + 1), y);
}
ll sum(int k, int a, int b) { return sum(ts[k], 0, n - 1, a, b); }

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int q;
  cin >> n >> q;
  xs = vector<int>(n);
  for (int i = 0; i < n; i++) cin >> xs[i];
  ts = vector<node *>();
  ts.push_back(build(0, n - 1));
  while (q--) {
    int t, k, a, b, x;
    cin >> t >> k, k--;
    if (t == 1) {
      cin >> a >> x;
      a--;
      update(k, a, x);
    } else if (t == 2) {
      cin >> a >> b;
      a--, b--;
      cout << sum(k, a, b) << '\n';
    } else
      copy(k);
  }
}
