// https://cses.fi/problemset/task/1085/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bool p(const vi &a, ll sum, int k) {
  ll s = 0;
  int i = 1;
  for (auto x : a) {
    if (x > sum) return false;
    if (s + x > sum) {
      s = x;
      i++;
    } else s += x;
  }
  return i <= k;
}

int main() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  ll s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  ll l = 0;
  for (ll i = s / 2; i >= 1; i /= 2) {
    while (l + i < s && !p(a, l + i, k)) l += i;
  }
  cout << l + 1 << endl;
}
