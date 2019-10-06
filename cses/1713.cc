// https://cses.fi/problemset/task/1713/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int N = 1000000;

int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  vi d(N + 1);
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i)
      d[j]++;
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> x, cout << d[x] << "\n";
}
