// https://codeforces.com/contest/1304/problem/D
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  ll t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    vector<int> a(n), b(n);
    int i = 0, j = 0, k = 1;
    while (i < n) {
      if (s[i] == '<') {
        for (int l = i; l >= j; l--)
          a[l] = k++;
        j = i+1;
      }
      i++;
    }
    for (int l = i-1; l >= j; l--)
      a[l] = k++;
    i = n-1, j = n-1, k = 1;
    while (i >= 0) {
      if (s[i] == '>') {
        for (int l = i+1; l <= j; l++)
          b[l] = k++;
        j = i;
      }
      i--;
    }
    for (int l = i+1; l <= j; l++)
      b[l] = k++;
    for (int i = 0; i < n; i++)
      cout << b[i] << " \n"[i==n-1];
    for (int i = 0; i < n; i++)
      cout << a[i] << " \n"[i==n-1];
  }
}
