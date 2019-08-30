// https://cses.fi/problemset/task/1095/
#include <iostream>

using namespace std;

typedef long long ll;

const int M = 1000000007;

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
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << pow(a, b, M) << endl;
  }
}
