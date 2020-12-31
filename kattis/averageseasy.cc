// https://open.kattis.com/problems/averageseasy
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, c, e;
  cin >> t;
  while (t--) {
    cin >> c >> e;
    vector<int> a(c), b(e);
    for (int i = 0; i < c; i++) cin >> a[i];
    for (int i = 0; i < e; i++) cin >> b[i];
    double aa = 0, ab = 0;
    for (int x : a) aa += x;
    for (int x : b) ab += x;
    aa /= c;
    ab /= e;
    int ans = 0;
    for (int x : a) ans += x < aa && x > ab;
    cout << ans << '\n';
  }
}
