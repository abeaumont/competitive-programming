// https://cses.fi/problemset/task/1735
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
  ll sum;
  ll inc;
  ll set;
};

const ll NONE = 1000000000000000000LL;

vector<node> tree;
int k = 1;

void push(int x, int y, int k) {
  int d = (x+y)/2;
  if (tree[k].set != NONE) {
    tree[2*k].set = tree[k].set;
    tree[2*k].inc = 0;
    tree[2*k].sum = tree[2*k].set * (d-x+1);
    tree[2*k+1].set = tree[k].set;
    tree[2*k+1].inc = 0;
    tree[2*k+1].sum = tree[2*k+1].set * (y-d);
  } else {
    if (tree[2*k].set != NONE) {
      tree[2*k].set += tree[k].inc;
      tree[2*k].sum = tree[2*k].set * (d-x+1);
    } else {
      tree[2*k].inc += tree[k].inc;
      tree[2*k].sum += tree[k].inc * (d-x+1);
    }
    if (tree[2*k+1].set != NONE) {
      tree[2*k+1].set += tree[k].inc;
      tree[2*k+1].sum = tree[2*k+1].set * (y-d);
    } else {
      tree[2*k+1].inc += tree[k].inc;
      tree[2*k+1].sum += tree[k].inc * (y-d);
    }
  }
  tree[k].set = NONE, tree[k].inc = 0;
}

ll sum(int a, int b, int k, int x, int y) {
  if (b < x || a > y) return 0;
  if (a <= x && y <= b) return tree[k].sum;
  push(x, y, k);
  int d = (x+y) / 2;
  return sum(a, b, 2*k, x, d) + sum(a, b, 2*k+1, d+1, y);
}
ll sum(int a, int b) { return sum(a, b, 1, 0, k - 1); }

void update(int a, int b, ll i, ll s, int k, int x, int y) {
  if (b < x || a > y) return;
  if (a <= x && y <= b) {
    if (s != NONE) {
      tree[k].set = s;
      tree[k].inc = 0;
      tree[k].sum = s * (y-x+1);
    } else if (tree[k].set != NONE) {
      tree[k].set += i;
      tree[k].sum = tree[k].set * (y-x+1);
    } else {
      tree[k].inc += i;
      tree[k].sum += i * (y-x+1);
    }
    return;
  }
  push(x, y, k);
  int d = (x+y)/2;
  update(a, b, i, s, 2*k, x, d);
  update(a, b, i, s, 2*k+1, d+1, y);
  tree[k].sum = tree[2*k].sum + tree[2*k+1].sum;
}

void increase(int a, int b, int x) { update(a, b, x, NONE, 1, 0, k - 1); }
void assign(int a, int b, int x) { update(a, b, 0, x, 1, 0, k - 1); }

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, q, x;
  cin >> n >> q;
  while (k < n) k *= 2;
  tree = vector<node>(2*k);
  for (int i = 0; i < n; i++) {
    cin >> x;
    tree[k+i] = {x,0,NONE};
  }
  for (int i = k - 1; i > 0; i--) {
    tree[i].sum = tree[i*2].sum + tree[i*2+1].sum;
    tree[i].set = NONE;
  }
  while (q--) {
    int k, a, b, x;
    cin >> k >> a >> b;
    a--, b--;
    if (k < 3) cin >> x;
    if (k == 1) increase(a, b, x);
    else if (k == 2) assign(a, b, x);
    else cout << sum(a, b) << '\n';
  }
}
