// https://atcoder.jp/contests/abc126/tasks/abc126_c
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  double p = 0;
  for (int i = 1; i <= n; i++) {
    double q = 1;
    for (int j = i; j < k; j *= 2) q /= 2;
    p += q/n;
  }
  cout << fixed << setprecision(20) << p << "\n";;
}
