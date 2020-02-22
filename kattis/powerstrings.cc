// https://open.kattis.com/problems/powerstrings
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  while (1) {
    cin >> s;
    if (s == ".") break;
    int n = s.size();
    vi pi(n);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < n; i++) {
      k = pi[i-1];
      while (k > 0 && s[i] != s[k]) k = pi[k-1];
      if (s[i] == s[k]) k++;
      pi[i] = k;
    }
    if (pi[n-1] >= n/2 && pi[n-1]%(n-pi[n-1]) == 0) cout << pi[n-1]/(n-pi[n-1])+1 << '\n';
    else cout << "1\n";
  }
}
