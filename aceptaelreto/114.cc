// https://www.aceptaelreto.com/problem/statement.php?id=114
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ll n, x;
  cin >> n;
  while (n--) {
    cin >> x;
    if (!x) cout << "1\n";
    else if (x == 3) cout << "6\n";
    else if (x < 5) cout << x << '\n';
    else cout << "0\n";
  }
}
