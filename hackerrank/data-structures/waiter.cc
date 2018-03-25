// https://www.hackerrank.com/challenges/waiter
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef stack<int> si;
typedef vector<si> vsi;

int primes[1201];

bool is_prime(int x) {
	for (int i = 2; i <= int(sqrt(x)); i++) {
		if ((x % i) == 0) return false;
	}
	return true;
}

void calc_primes(int q) {
	primes[0] = 2;
	primes[1] = 3;
	int c = 2;
	for (int i = 5; c < q; i++) {
		if (is_prime(i)) {
			primes[c] = i;
			c++;
		}
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	calc_primes(q);
	vsi v(q + 2);
	while (n--) {
		int x;
		cin >> x;
		v[q].push(x);
	}
	for (int i = 0; i < q; i++) {
		int k = q + (i % 2);
		int k2 = q + (i % 2 == 0);
		while (!v[k].empty()) {
			int x = v[k].top();
			v[k].pop();
			if (x % primes[i]) {
				v[k2].push(x);
			} else {
				v[i].push(x);
			}
		}
	}
	for (int i = 0; i < q + 2; i++) {
		while (!v[i].empty()) {
			cout << v[i].top() << endl;
			v[i].pop();
		}
	}
}
