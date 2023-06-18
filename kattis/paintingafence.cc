// https://open.kattis.com/problems/paintingafence
#include <bits/stdc++.h>

using namespace std;
const int N = 300, M = 1e4;
int R[N][M + 1];
vector<pair<int, int>> C[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  unordered_map<string, int> m;
  int n, a, b, nc = 0;
  string cs;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cs >> a >> b;
    auto it = m.find(cs);
    if (it == m.end()) m[cs] = nc++;
    C[m[cs]].push_back({a, b});
  }
  for (int i = 0; i < nc; i++) {
    sort(C[i].begin(), C[i].end());
    for (auto &[a, b] : C[i])
      for (int j = a; j <= b; j++) R[i][j] = max(R[i][j], b + 1);
  }
  int best = N + 1;
  for (int i = 0; i < nc; i++)
    for (int j = i; j < nc; j++)
      for (int k = j; k < nc; k++) {
        int mx = 1, count = 0;
        while (mx <= M) {
          mx = max(max(R[i][mx], R[j][mx]), R[k][mx]);
          if (!mx) {
            count = N + 1;
            break;
          }
          count++;
        }
        best = min(best, count);
      }
  if (best == N + 1) cout << "IMPOSSIBLE\n";
  else
    cout << best << '\n';
}
