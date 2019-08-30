// https://cses.fi/problemset/task/1157
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ll y, x;
  cin >> y >> x;
  y--; x--;
  ll m = max(y, x);
  ll k = 1;
  while (k * 4 <= m) k *= 4;
  ll c = 0;
  while (k > 0) {
    ll a = y / k;
    ll b = x / k;
    if (a + b == 3) c += 3 * k;
    else c += abs(a - b) * k;
    y %= k;
    x %= k;
    k /= 4;
  }
  cout << c << endl;
}
