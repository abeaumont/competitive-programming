// https://www.aceptaelreto.com/problem/statement.php?id=100
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, x;
  cin >> n;
  while (n--) {
    cin >> x;
    int k;
    for (k = 0; x && x != 6174; k++) {
      vector<int> d;
      while (x) {
        d.push_back(x % 10);
        x /= 10;
      }
      while (d.size() < 4) d.push_back(0);
      sort(d.begin(), d.end());
      int a = 0, b = 0;
      for (int i = 0; i < d.size(); i++)
        a = a * 10 + d[i], b = b * 10 + d[d.size() - i - 1];
      x = b - a;
    }
    if (x) cout << k << "\n";
    else cout << "8\n";
  }
}
