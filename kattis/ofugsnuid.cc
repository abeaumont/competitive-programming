// https://open.kattis.com/problems/ofugsnuid
#include <bits/stdc++.h>

const int N = 1e5;
int x[N];

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  while (n--) cout << x[n] << '\n';
}
