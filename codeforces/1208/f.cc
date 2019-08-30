// https://codeforces.com/contest/1208/problem/F
#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;


int N = 1 << 21;
vvi b(N);
int k;

void f(int x, int i) {
  if (i < 0) {
    if (b[x].size() < 2) b[x].push_back(k);
    return;
  }
  if (b[x].size() < 2) {
    f(x, i - 1);
    if (x & (1 << i)) f(x & ~(1 << i), i - 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m = 0;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = n - 1; j >= 0; j--) k = j, f(a[j], 20);
  for (int i = 0; i < n - 2; i++) {
    int w = 0;
    for (int j = 20; j >= 0; j--)
      if (!(a[i] & (1 << j)))
        if (b[w | (1 << j)].size() >= 2 && b[w | (1 << j)][1] > i)
          w |= 1 << j;
    m = max(m, a[i] | w);
  }
  cout << m << "\n";
}
