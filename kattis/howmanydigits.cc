// https://open.kattis.com/problems/howmanydigits
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1000000;
double logs[MAXN + 1];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  for (int i = 1; i <= MAXN; i++) logs[i] = logs[i - 1] + log10(double(i));
  int n;
  while (cin >> n) cout << int(logs[n]) + 1 << '\n';
}
