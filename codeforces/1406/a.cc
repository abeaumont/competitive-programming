// https://codeforces.com/contest/1406/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(101);
    for (int i = 0; i < n; i++) {
      cin >> x;
      a[x]++;
    }
    int s = 0, c = 0;
    for (int i = 0; i <= 100; i++) {
      if (!a[i]) {
        s += i;
        c++;
        if (c == 2) break;
        s += i;
        c++;
        break;
      }
      if (!c && a[i] < 2) c++, s += i;
    }
    cout << s << '\n';
  }
}
