// https://cses.fi/problemset/task/2164
#include <bits/stdc++.h>

using namespace std;

int main() {
  int q, k, n;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    int m = 1;
    while (m * 2 <= n) m *= 2;
    int d = n - m;
    if (k == n) {
      cout << 2 * d + 1 << '\n';
      continue;
    }
    k--;
    vector<int> xs;
    for (int i = m / 2; i >= 1; i /= 2) xs.push_back(i);
    xs.push_back(1);
    for (int i = 0; i < xs.size() - 1; i++) {
      xs[i] += d / (1 << (i + 1));
      if (i) xs[i] += bool((d & (1 << (i - 1))));
    }
    if (d >= m / 2) xs.push_back(1);
    int o = 2;
    if (k < xs[0]) {
      cout << o + 2 * k << '\n';
      continue;
    }
    k -= xs[0];
    for (int j = 1; j < xs.size() - 1; j++) {
      o += (1 << (j - 1));
      if (k < xs[j]) {
        int q = (o + 2 * d) % (1 << (j + 1));
        cout << q + k * (1 << (j + 1)) << '\n';
        break;
      }
      k -= xs[j];
    }
  }
}
