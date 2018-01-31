// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/classic-task-39656dbf/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_set<int> si;
typedef vector<si> vsi;

void dfs(const vsi &g, si &s, int i) {
  for (auto x : g[i]) {
    auto it = s.find(x);
    if (it != s.end()) {
      s.erase(it);
      dfs(g, s, *it);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vsi g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    for (int i = a, j = b; i <= (a + b) / 2; i++, j--) {
      g[i - 1].insert(j - 1);
      g[j - 1].insert(i - 1);
    }
  }
  si s;
  for (int i = 0; i < n; i++) s.insert(i);
  int c = 0;
  while (!s.empty()) {
    auto it = s.begin();
    s.erase(*it);
    dfs(g, s, *it);
    c++;
  }
  cout << c << endl;
}
