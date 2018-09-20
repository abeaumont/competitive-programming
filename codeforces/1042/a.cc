// https://codeforces.com/contest/1042/problem/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll n,m,x,s=0,M=0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s += x;
    M = max(M, x);
  }
  cout << max((s+m+n-1)/n, M) << " " << M+m << endl;
}
