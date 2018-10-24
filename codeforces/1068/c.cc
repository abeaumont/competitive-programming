// https://codeforces.com/contest/1068/problem/C
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n, m;
  cin >> n >> m;
  vvi g(n);
  vvi h(n);
  for (int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v;
    u--;v--;
    if (v<u) swap(u,v);
    g[u].push_back(v);
  }
  int x = 0;
  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end());
    h[i].push_back(x++);
    for (auto u:g[i]) {
      h[i].push_back(x);
      h[u].push_back(x);
      x++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << h[i].size() << endl;
    for (int j = 0; j < h[i].size(); j++) cout << h[i][j]+1 << " " << i+1 << endl;
  }
}
