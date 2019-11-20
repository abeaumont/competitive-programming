// https://codeforces.com/contest/1131/problem/F
#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vi p;
vvi r;

int find(int i) {
  if (i == p[i]) return i;
  return p[i] = find(p[i]);
};

void unite(int i, int j) {
  i = find(i);
  j = find(j);
  if (i == j) return;
  if (r[i].size() < r[j].size()) swap(i,j);
  for (int x : r[j]) r[i].push_back(x);
  p[j] = i;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, u, v;
  cin >> n;
  p = vi(n), r = vvi(n);
  for(int i = 0; i < n; i++) p[i] = i, r[i] = vi(1, i + 1);
  for(int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--, v--;
    unite(u, v);
  }
  vi &x = r[find(0)];
  for (int i = 0; i < n; i++) cout << x[i] << " \n"[i == n-1];
}
