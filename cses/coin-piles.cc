// https://cses.fi/problemset/task/1754/
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    cout << (!((a + b) % 3) && min(a, b) * 2 >= max(a, b) ? "YES\n" : "NO\n");
  }
}
