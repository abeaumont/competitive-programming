// https://open.kattis.com/problems/boatparts
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int p, n;
  cin >> p >> n;
  set<string> s;
  string t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    s.insert(t);
    if (s.size() == p) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << "paradox avoided\n";
}
