// https://cses.fi/problemset/task/2217/
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, a, b;
  cin >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) cin >> x[i], x[i]--, y[x[i]] = i;
  int s = 1;
  for (int i = 1; i < n; i++) s += y[i] < y[i - 1];
  int k = 0;
  while (m--) {
    k++;
    cin >> a >> b;
    a--, b--;
    if (a > b) swap(a, b);
    int p = x[a], q = x[b];
    swap(x[a], x[b]);
    swap(y[p], y[q]);
    int pre = s;
    if (p && y[p - 1] >= a && y[p - 1] <= b) s--;
    if (p < n - 1 && y[p + 1] >= a && y[p + 1] <= b) s++;
    if (q && y[q - 1] >= a && y[q - 1] <= b) s++;
    if (q < n - 1 && y[q + 1] >= a && y[q + 1] <= b) s--;
    if (p + 1 == q) s--;
    if (p == q + 1) s++;
    cout << s << '\n';
  }
}
