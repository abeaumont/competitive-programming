// https://atcoder.jp/contests/abc126/tasks/abc126_b
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if ((n / 100 == 0 || n / 100 > 12) && (n % 100 == 0 || n % 100 > 12)) cout << "NA\n";
  else if (n / 100 == 0 || n / 100 > 12) cout << "YYMM\n";
  else if (n % 100 == 0 || n % 100 > 12) cout << "MMYY\n";
  else cout <<"AMBIGUOUS\n";
}
