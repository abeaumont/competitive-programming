// https://cses.fi/problemset/task/1633/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = max(0, i - 6); j < i; j++)
      a[i] = (a[i] + a[j]) % 1000000007;
  cout << a.back() << "\n";
}
