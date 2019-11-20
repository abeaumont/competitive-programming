// https://codeforces.com/contest/1061/problem/C
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int N = 1000000;
int M = 1e9+7;

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  int n, x;
  cin >> n;
  vvi d(N + 1);
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i)
      d[j].push_back(i);
  vi r(1, 1);
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = d[x].size() - 1; j >= 0; j--) {
      int y = d[x][j];
      if (r.size() == y) r.push_back(r[y - 1]);
      else if (r.size() > y) (r[y] += r[y - 1]) %= M;
    }
  }
  int s = r[0] = 0;
  for (int x : r) (s += x) %= M;
  cout << s << '\n';
}
