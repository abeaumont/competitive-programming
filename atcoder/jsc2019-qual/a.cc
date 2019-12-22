// https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_a
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, d, c = 0;
  cin >> m >> d;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= d; j++) {
      int d1 = j % 10, d10 = j / 10;
      c += d1 >= 2 && d10 >= 2 && d1 * d10 == i;
    }
  cout << c << "\n";
}
