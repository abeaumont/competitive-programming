// https://open.kattis.com/problems/pikemaneasy
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const int MOD = 1000000007;

int main() {
  ll n, t, a, b, c;
  cin >> n >> t >> a >> b >> c;
  vll v(n);
  cin >> v[0];
  for (int i = 1; i < n; i++) {
    v[i] = (v[i - 1] * a + b) % c + 1;
  }
  sort(v.begin(), v.end());
  ll s = 0;
	ll total = 0;
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (s + v[i] > t) break;
		s += v[i];
    total = (total + s) % MOD;
    k++;
  }
  cout << k << " " << total << endl;
}
