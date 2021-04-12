// https://www.codechef.com/APRIL21A/problems/MEXSTR
#include <bits/stdc++.h>

using namespace std;

const int N = 1000000, NONE = 1e9;
int p[N + 1], ones[N + 1], zeros[N + 1];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size(), o = n, z = n;
    ones[n] = o, zeros[n] = z, p[n] = NONE;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') z = i;
      else
        o = i;
      ones[i] = o, zeros[i] = z, p[i] = NONE;
    }
    if (zeros[0] == n) {
      cout << '0' << '\n';
      continue;
    }
    if (ones[0] == n) {
      cout << '1' << '\n';
      continue;
    }
    queue<int> q;
    p[ones[0]] = -1;
    q.push(ones[0]);
    vector<char> ans;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      int v = zeros[u + 1];
      if (p[v] == NONE) {
        p[v] = u;
        if (v == n) {
          ans.push_back('0');
          break;
        }
        q.push(v);
      }
      v = ones[u + 1];
      if (p[v] == NONE) {
        p[v] = u;
        if (v == n) {
          ans.push_back('1');
          break;
        }
        q.push(v);
      }
    }
    int x = n;
    while (p[x] != -1) ans.push_back(s[p[x]]), x = p[x];
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
    cout << '\n';
  }
}
