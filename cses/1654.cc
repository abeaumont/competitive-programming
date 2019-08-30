// https://cses.fi/problemset/task/1654/
#include <bits/stdc++.h>

using namespace std;

int N = 21;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(1 << N), c(1 << N);
  for (int i = 0; i < n; i++) cin >> a[i], b[a[i]]++, c[a[i]]++;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < (1 << N); j++)
      if (j & (1 << i)) b[j] += b[j ^ (1 << i)];
      else c[j] += c[j ^ (1 << i)];
  for (int x : a)
    cout << b[x] << " " << c[x] << " " << n - b[(1 << N) - x - 1] << "\n";
}
