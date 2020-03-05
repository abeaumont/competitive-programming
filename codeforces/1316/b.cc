// https://codeforces.com/contest/1316/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = tuple<int, int>;
using vi = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using si = set<ll>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n, c;
  string s, best;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    string s2 = s + s;
    best = s, c = 0;
    for (int k = 1; k < n; k++) {
      if (n%2 == k%2) {
        for (int i = 0; i < n; i++)
          if (s2[k+i] < best[i]) {
            c = k;
            best = s2.substr(k, n);
            break;
        } else if (s2[k+i] > best[i]) break;
      } else {
        int i = 0;
        for (; i < n-k; i++) {
          if (s2[k+i] < best[i]) {
            c = k;
            best = s2.substr(k, n-k);
            string s3 = s.substr(0, k);
            reverse(s3.begin(), s3.end());
            best += s3;
            break;
          } else if (s2[k+i] > best[i]) break;
        }
        if (i < n-k) continue;
        for (; i<n; i++) {
          if (s2[n-i-1] < best[i]) {
            c = k;
            best = s2.substr(k, n-k);
            string s3 = s.substr(0, k);
            reverse(s3.begin(), s3.end());
            best += s3;
            break;
          } else if (s2[n-i-1] > best[i]) break;
        }
      }
    }
    cout << best << endl;
    cout << c+1 << endl;
  }
}
