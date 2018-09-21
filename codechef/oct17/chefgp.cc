// https://www.codechef.com/OCT17/problems/CHEFGP/
#include <iostream>

using namespace std;

void f() {
	string s;
		int x, y;
		cin >> s >> x >> y;
		int a = 0;
		int b = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'a') a++;
			else b++;
		}
		int ca = (a + x - 1) / x;
		int cb = (b + y - 1) / y;
		if (ca == cb) {
			while (a >= x && b >= y) {
				for (int k = 0; k < x; k++) cout << 'a';
				a -= x;
				for (int k = 0; k < y; k++) cout << 'b';
				b -= y;
			}
			for (int k = 0; k < a; k++) cout << 'a';
			for (int k = 0; k < b; k++) cout << 'b';
			cout << endl;
			return;
		}
		if (ca > cb && b >= ca) {
			int kb = b / ca;
			int mb = b % ca;
			while (a >= x) {
				for (int k = 0; k < x; k++) cout << 'a';
				a -= x;
				int l = kb + (mb ? 1 : 0);
				for (int k = 0; k < l; k++) cout << 'b';
				b -= l;
				if (mb) mb--;
			}
			for (int k = 0; k < a; k++) cout << 'a';
			for (int k = 0; k < b; k++) cout << 'b';
			cout << endl;
			return;
		}
		if (ca > cb) {
			while (b > 0) {
				for (int k = 0; k < x; k++) cout << 'a';
				a -= x;
				cout << 'b';
				b--;
			}
			while (a > 0) {
				int l = min(a, x);
				for (int k = 0; k < l; k++) cout << 'a';
				a -= l;
				if (a) cout << '*';
			}
			cout << endl;
			return;
		}
		if (ca < cb && a >= cb) {
			int ka = a / cb;
			int ma = a % cb;
			while (b >= y) {
				for (int k = 0; k < y; k++) cout << 'b';
				b -= y;
				int l = ka + (ma ? 1 : 0);
				for (int k = 0; k < l; k++) cout << 'a';
				a -= l;
				if (ma) ma--;
			}
			for (int k = 0; k < b; k++) cout << 'b';
			for (int k = 0; k < a; k++) cout << 'a';
			cout << endl;
			return;
		}
		while (a > 0) {
			for (int k = 0; k < y; k++) cout << 'b';
			b -= y;
			cout << 'a';
			a--;
		}
		while (b > 0) {
			int l = min(b, y);
			for (int k = 0; k < l; k++) cout << 'b';
			b -= l;
			if (b) cout << '*';
		}
		cout << endl;
		return;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		f();
	}
}
