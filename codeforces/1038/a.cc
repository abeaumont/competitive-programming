// https://codeforces.com/contest/1038/problem/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[26];

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) a[s[i] - 'A']++;
  int m = n;
  for (int i = 0; i < k; i++) m = min(m, a[i]);
  cout << m * k << endl;
}
