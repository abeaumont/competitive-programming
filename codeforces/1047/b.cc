// https://codeforces.com/contest/1047/problem/B
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll n,x,y,m=0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    m = max(m, x+y);
  }
  cout << m << endl;
}
