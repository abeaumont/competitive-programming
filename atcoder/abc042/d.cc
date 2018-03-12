// https://abc042.contest.atcoder.jp/tasks/arc058_b
#include <iostream>
#include <vector>
     
using namespace std;
     
typedef long long ll;
typedef vector<ll> vll;
     
const ll MOD = 1000000007;
     
ll pow(ll a, ll b) {
	ll x = 1, y = a;
	while(b > 0) {
		if(b % 2) x = (x * y) % MOD;
		y = (y * y) % MOD;
		b /= 2;
	}
	return x;
}
         
ll inv(ll n) {
	return pow(n, MOD - 2);
}
     
ll f(ll n) {
	ll k = 1;
	for (ll i = 1; i <= n; i++) k = (k * i) % MOD;
	return k;
}
     
int main() {
	ll h, w, a, b;
	cin >> h >> w >> a >> b;
	ll s = 0;
	ll p1, p2;
	vll p3(w - b);
	vll p4(w - b);
	p3[w - b - 1] = f((a - 1));
	p4[w - b - 1] = p3[w - b - 1];
	for (int i = w - 2; i >= b; i--) {
		p3[i - b] = (p3[i - b + 1] * (a - 1 + w - i - 1)) % MOD;
		p4[i - b] = (p4[i - b + 1] * (w - i - 1)) % MOD;
	}
	for (int i = b; i < w; i++) {
		if (i == b) {
			p1 = f((h - a - 1) + i);
			p2 = (f(h - a - 1) * f(i)) % MOD;
		} else {
			p1 = (p1 * (h - a - 1 + i)) % MOD;
			p2 = (p2 * i) % MOD;
		}
		ll s1 = (p1 * inv(p2)) % MOD;
		ll s2 = (p3[i - b] * inv(p4[i - b])) % MOD;
		s1 = (s1 * s2) % MOD;
		if (s1 < 0) s1 += MOD;
		s = (s + s1) % MOD;
	}
	cout << s << endl;
}
