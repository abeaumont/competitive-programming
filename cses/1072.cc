// https://cses.fi/problemset/task/1072/
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    ll a = i * i * (i * i - 1) / 2;
    ll b = 2 * (i - 2) * (2 * (i - 4) + 6);
    cout << a - b << endl;
  }
  return 0;
}
