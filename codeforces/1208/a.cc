// https://codeforces.com/contest/1208/problem/A
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, n;
    cin >> a >> b >> n;
    ll r[] = {a, b, a ^ b};
    cout << r[n%3] <<"\n";
  }
}
