// https://cses.fi/problemset/task/1619/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y, s = 0;
  priority_queue<tuple<int, bool>> q;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    q.push({-x, true});
    q.push({-y, false});
  }
  x = 0;
  while (!q.empty()) {
    x += get<1>(q.top()) ? 1 : -1;
    q.pop();
    s = max(s, x);
  }
  cout << s << "\n";
}
