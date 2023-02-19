// https://codingcompetitions.withgoogle.com/codejam/round/0000000000432bd2/0000000000433082
#include <bits/stdc++.h>

using namespace std;

struct node {
  node *left, *right;
  int weight, size, value;
  node(int v) {
    left = right = nullptr;
    weight = rand();
    size = 1;
    value = v;
  }
};

int size(node *treap) { return treap ? treap->size : 0; }

void split(node *treap, node *&left, node *&right, int k) {
  if (!treap) {
    left = right = nullptr;
    return;
  }
  if (size(treap->left) < k) {
    split(treap->right, treap->right, right, k - size(treap->left) - 1);
    left = treap;
  } else {
    split(treap->left, left, treap->left, k);
    right = treap;
  }
  treap->size = size(treap->left) + size(treap->right) + 1;
}

void merge(node *&treap, node *left, node *right) {
  if (!left) {
    treap = right;
    return;
  }
  if (!right) {
    treap = left;
    return;
  }
  if (left->weight < right->weight) {
    merge(left->right, left->right, right);
    treap = left;
  } else {
    merge(right->left, left, right->left);
    treap = right;
  }
  treap->size = size(treap->left) + size(treap->right) + 1;
}

void treap2vector(node *treap, vector<int> &v) {
  if (!treap) return;
  treap2vector(treap->left, v);
  v.push_back(treap->value);
  treap2vector(treap->right, v);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  srand(time(0));
  int t, k, n;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> k >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    node *treap = nullptr;
    for (int i = 0; i < k; i++) {
      merge(treap, treap, new node(k - i));
      int pos = (k - i - 1) % (i + 1);
      if (pos != i) {
        node *left, *right;
        split(treap, left, right, i - pos);
        merge(treap, right, left);
      }
    }
    vector<int> ans;
    treap2vector(treap, ans);
    cout << "Case #" << T << ':';
    for (int x : d) cout << ' ' << ans[x - 1];
    cout << '\n';
  }
}
