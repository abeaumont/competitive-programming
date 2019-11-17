// https://codeforces.com/contest/1241/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  int q, n;
  cin >> q;
  while (q--) {
    cin >> n;
    if (n == 2) cout << 2 << endl;
    else if (n % 2) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
