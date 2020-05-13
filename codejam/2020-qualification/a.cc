// https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, t;
  cin >> t;
  for (int T = 1; T <= t; T++) {
    cin >> n;
    vvi a(n, vi(n));
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        cin >> a[i][j];
    int k=0, r=0, c=0;
    for (int i=0; i<n; i++) {
      vi s(n);
      for (int j=0; j<n; j++) {
        if (s[a[i][j]-1]) {
          r++;
          break;
        }
        s[a[i][j]-1]++;
      }
    }
    for (int i=0; i<n; i++) {
      vi s(n);
      for (int j=0; j<n; j++) {
        if (s[a[j][i]-1]) {
          c++;
          break;
        }
        s[a[j][i]-1]++;
      }
    }
    for (int i=0; i<n; i++)
      k += a[i][i];
    cout << "Case #" << T << ": " << k << ' ' << r << ' ' << c << '\n';
  }
}
