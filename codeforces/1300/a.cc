// https://codeforces.com/contest/1300/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, x;
  cin >> t;
  while (t--) {
    cin >> n;
    int sum = 0, zeros = 0;
    while (n--) {
      cin >> x;
      if (x == 0) zeros++;
      sum += x;
    }
    cout << (zeros + (sum + zeros == 0)) << '\n';
  }
}
