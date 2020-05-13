// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
#include <bits/stdc++.h>

using namespace std;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using viii = vector<iii>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  for (int T=1; T<=t; T++) {
    cin >> n;
    viii a(2*n);
    for (int i=0; i<n; i++) {
      int s, e;
      cin >> s >> e;
      a[2*i] = {s, 1, i+1};
      a[2*i+1] = {e, 0, i+1};
    }
    sort(a.begin(), a.end());
    string r(n, '0');
    vi s(2);
    for (int i=0; i<2*n; i++) {
      int t, k, j;
      tie(t, k, j) = a[i];
      if (!k) s[s[1] == j] = 0;
      else {
        if (s[0] && s[1]) {
          r = "IMPOSSIBLE";
          break;
        } else if (s[0]) s[1] = j, r[j-1] = 'C';
        else s[0] = j, r[j-1] = 'J';
      }
    }
    cout << "Case #" << T << ": " << r << '\n';
  }
}
