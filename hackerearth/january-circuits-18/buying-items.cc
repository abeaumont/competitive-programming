// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/buying-items-d552af6f/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_set<int> si;

ll best = 1000000000LL * 500 + 1;

void s(const vvi &v, si &x, int m, int n, int k, ll c) {
  if (x.size() == n) best = min(best, c);
  if (k == m) return;
  s(v, x, m, n, k + 1, c);
  si set;
  for (int i = 0; i < n; i++) {
    if (v[k][i] && !x.count(i)) {
      set.insert(i);
      x.insert(i);
    }
  }
  if (!set.empty()) {
    s(v, x, m, n, k + 1, c + v[k][n]);
    for (auto i : set) x.erase(i);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vvi v(m);
  for (int i = 0; i < m; i++) {
    v[i] = vi(n + 1);
    for (int j = 0; j <= n; j++) {
      cin >> v[i][j];
    }
  }
  si x;
  s(v, x, m, n, 0, 0);
  cout << best << endl;
}
