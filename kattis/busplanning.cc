// https://open.kattis.com/problems/busplanning
#include <bits/stdc++.h>

using namespace std;
const int N = 17;
bool g[N][N];
bool s[N];

vector<vector<string>> best;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, k, c;
  cin >> n >> k >> c;
  map<string, int> idx;
  vector<string> ns(n);
  for (int i = 0; i < n; i++) {
    cin >> ns[i];
    idx[ns[i]] = i;
  }
  for (int i = 0; i < k; i++) {
    string a, b;
    cin >> a >> b;
    g[idx[a]][idx[b]] = 1;
    g[idx[b]][idx[a]] = 1;
  }
  for (int K = 0; K < 1000; K++) {
    fill(s, s + n, 0);
    vector<vector<string>> ans;
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    random_shuffle(order.begin(), order.end());
    while (true) {
      vector<int> xs;
      for (int i : order) {
        if (!s[i]) {
          bool ok = 1;
          for (int x : xs)
            if (g[x][i]) {
              ok = 0;
              break;
            }
          if (ok) {
            xs.push_back(i);
            s[i] = 1;
            if (xs.size() == c) break;
          }
        }
      }
      if (xs.empty()) break;
      ans.push_back(vector<string>());
      for (int x : xs) ans.back().push_back(ns[x]);
    }
    if (best.empty() || ans.size() < best.size()) swap(ans, best);
  }
  cout << best.size() << '\n';
  for (auto xs : best)
    for (int i = 0; i < xs.size(); i++)
      cout << xs[i] << " \n"[i == xs.size() - 1];
}
