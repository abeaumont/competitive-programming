// https://cses.fi/problemset/task/1146/
#include <cmath>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef unsigned long long ll;

unordered_map<ll, ll> cache;

ll c(ll n) {
	if (n == 0) return 0;
	if (cache[n]) return cache[n];
	ll z = n;
	ll a = 1;
	while (z >>= 1) a <<= 1;
	a -= 1;
	ll b = n - a;
	cache[n] = c(a) + b + c(b - 1);
	return cache[n];
}

int main() {
	ll n;
	cin >> n;
	cout << c(n) << endl;;
}
