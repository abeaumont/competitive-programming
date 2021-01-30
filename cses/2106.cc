// https://cses.fi/problemset/task/2106
#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using viii = vector<iii>;

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int n, k = 0, m = 0, x, y, z;
  string s;
  cin >> s, n = s.size();
  vvi p(1, vi(n));
  for (int i = 0; i < n; i++) p[0][i] = s[i];
  for (int k = 1; k < n; k *= 2) {
    viii l(n);
    for (int i = 0; i < n; i++)
      l[i] = {p.back()[i], i + k < n ? p.back()[i + k] : -1, i};
    sort(l.begin(), l.end());
    p.push_back(vi(n));
    for (int i = 0, j = 0; i < n; i++) {
      tie(x, y, z) = l[i];
      if (i && (get<0>(l[i - 1]) != x || get<1>(l[i - 1]) != y)) j++;
      p.back()[z] = j;
    }
  }
  vi sa(n), lcp(n), rank(n);
  for (int i = 0; i < n; i++) sa[p.back()[i]] = i;
  for (int i = 0; i < n; i++) rank[sa[i]] = i;
  for (int i = 0; i < n; i++)
    if (rank[i]) {
      int j = sa[rank[i] - 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
      lcp[i] = k;
      if (k) k--;
    }
  for (int i = 0; i < n; i++)
    if (lcp[i] > m) m = lcp[i], k = i;
  if (m)
    for (int i = k; i < k + m; i++) cout << s[i];
  else
    cout << "-1";
  cout << '\n';
}
