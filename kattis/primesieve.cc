// https://open.kattis.com/problems/primesieve
#include <bits/stdc++.h>

using namespace std;
const int N = 100000000;
bitset<N+1> p;

int main() {
  int n, q, x;
  cin >> n >> q;
  p.set(1);
  for (int i = 2; i <= n; i++)
    if (!p[i])
      for (int j = i * 2; j <= n; j += i)
        p.set(j);
  cout << n - p.count() << '\n';
  while (q--) {
    cin >> x;
    cout << !p[x] << '\n';
  }
}
