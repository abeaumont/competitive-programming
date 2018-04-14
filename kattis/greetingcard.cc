// https://open.kattis.com/problems/greetingcard
#include <iostream>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unordered_set<ll> sl;

const ll P = 2147483648LL;
int X[12] = {0, 0, 2018, -2018, 1118, 1118, -1118, -1118, 1680, 1680, -1680, -1680};
int Y[12] = {2018, -2018, 0, 0, 1680, -1680, 1680, -1680, 1118, -1118, 1118, -1118};

int main() {
	ll n, x, y;
	cin >> n;
	sl s;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		s.insert(x * P + y);
	}
	int c = 0;
	for (ll z : s) {
		x = z / P;
		y = z % P;
		for (int i = 0; i < 12; i++)
			if (s.count((x + X[i]) * P + y + Y[i])) c++;
	}
	cout << c / 2 << endl;
}
