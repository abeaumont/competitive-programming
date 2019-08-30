// https://cses.fi/problemset/task/1617
#include <iostream>

using namespace std;
using ll = long long;

const ll M = 1000000007;

int pow(ll a, ll b, int m) {
  ll r = 1, e = a;
  while (b) {
    if (b & 1) r = (r * e) % m;
    e = (e * e) % m;
    b >>= 1;
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << pow(2, n, M) << "\n";
}
