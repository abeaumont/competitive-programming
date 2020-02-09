// https://codeforces.com/contest/1300/problem/C
#include <bits/stdc++.h>

using namespace std;

int bits[32];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m = 1;
    for (int j = 0; j < 32; j++, m *= 2)
      if (a[i] & m) {
        if (!bits[j]) bits[j] = i + 1;
        else bits[j] = -1;
      }
  }
  vector<int> r, s(n);
  for (int j = 31; j >= 0; j--) {
    if (bits[j] > 0 && !s[bits[j]-1]) {
      r.push_back(bits[j]-1);
      s[bits[j]-1] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    if (!s[i])
      r.push_back(i);
  for (int i = 0; i < n; i++)
    cout << a[r[i]] << " \n"[i == n - 1];
}
