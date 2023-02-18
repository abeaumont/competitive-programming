// https://codingcompetitions.withgoogle.com/codejam/round/00000000004330f6/00000000004329f4
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int c, n, m, t, x, y;
  cin >> c;
  for (int T = 1; T <= c; T++) {
    cin >> n >> m;
    vector<map<int, bool>> likes(m);
    vector<bool> malted(n);
    for (int i = 0; i < m; i++) {
      cin >> t;
      for (int j = 0; j < t; j++) {
        cin >> x >> y;
        likes[i][x - 1] = y;
      }
    }

    bool ok = 1;
    while (true) {
      vector<int> q;
      for (int i = 0; i < m; i++)
        if (likes[i].size() == 1 && likes[i].begin()->second == 1 &&
            !malted[likes[i].begin()->first]) {
          q.push_back(likes[i].begin()->first);
          malted[likes[i].begin()->first] = 1;
        }
      if (q.empty()) break;
      for (int k : q) {
        for (int i = 0; i < m; i++) {
          auto it = likes[i].find(k);
          if (it != likes[i].end() && it->second == 0) likes[i].erase(it);
          if (likes[i].empty()) ok = 0;
        }
      }
      if (!ok) break;
    }
    cout << "Case #" << T << ": ";
    if (ok)
      for (int i = 0; i < n; i++) cout << int(malted[i]) << " \n"[i == n - 1];
    else
      cout << "IMPOSSIBLE\n";
  }
}
