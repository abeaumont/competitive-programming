// https://open.kattis.com/problems/4thought
#include <iostream>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef tuple<int, int, int> iii;
typedef unordered_map<int, iii> map;

int main() {
	map m;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if (i == 0 && j == 0 && k == 0) m[4 * 4 * 4 * 4] = make_tuple(0, 0, 0);
				else if (i == 0 && j == 0 && k == 1) m[4 * 4 * 4 / 4] = make_tuple(0, 0, 1);
				else if (i == 0 && j == 0 && k == 2) m[4 * 4 * 4 + 4] = make_tuple(0, 0, 2);
				else if (i == 0 && j == 0 && k == 3) m[4 * 4 * 4 - 4] = make_tuple(0, 0, 3);
				else if (i == 0 && j == 1 && k == 0) m[4 * 4 / 4 * 4] = make_tuple(0, 1, 0);
				else if (i == 0 && j == 1 && k == 1) m[4 * 4 / 4 / 4] = make_tuple(0, 1, 1);
				else if (i == 0 && j == 1 && k == 2) m[4 * 4 / 4 + 4] = make_tuple(0, 1, 2);
				else if (i == 0 && j == 1 && k == 3) m[4 * 4 / 4 - 4] = make_tuple(0, 1, 3);
				else if (i == 0 && j == 2 && k == 0) m[4 * 4 + 4 * 4] = make_tuple(0, 2, 0);
				else if (i == 0 && j == 2 && k == 1) m[4 * 4 + 4 / 4] = make_tuple(0, 2, 1);
				else if (i == 0 && j == 2 && k == 2) m[4 * 4 + 4 + 4] = make_tuple(0, 2, 2);
				else if (i == 0 && j == 2 && k == 3) m[4 * 4 + 4 - 4] = make_tuple(0, 2, 3);
				else if (i == 0 && j == 3 && k == 0) m[4 * 4 - 4 * 4] = make_tuple(0, 3, 0);
				else if (i == 0 && j == 3 && k == 1) m[4 * 4 - 4 / 4] = make_tuple(0, 3, 1);
				else if (i == 0 && j == 3 && k == 2) m[4 * 4 - 4 + 4] = make_tuple(0, 3, 2);
				else if (i == 0 && j == 3 && k == 3) m[4 * 4 - 4 - 4] = make_tuple(0, 3, 3);
				else if (i == 1 && j == 0 && k == 0) m[4 / 4 * 4 * 4] = make_tuple(1, 0, 0);
				else if (i == 1 && j == 0 && k == 1) m[4 / 4 * 4 / 4] = make_tuple(1, 0, 1);
				else if (i == 1 && j == 0 && k == 2) m[4 / 4 * 4 + 4] = make_tuple(1, 0, 2);
				else if (i == 1 && j == 0 && k == 3) m[4 / 4 * 4 - 4] = make_tuple(1, 0, 3);
				else if (i == 1 && j == 1 && k == 0) m[int(4 / 4 / 4) * 4] = make_tuple(1, 1, 0);
				else if (i == 1 && j == 1 && k == 1) m[int(4 / 4 / 4) / 4] = make_tuple(1, 1, 1);
				else if (i == 1 && j == 1 && k == 2) m[int(4 / 4 / 4) + 4] = make_tuple(1, 1, 2);
				else if (i == 1 && j == 1 && k == 3) m[int(4 / 4 / 4) - 4] = make_tuple(1, 1, 3);
				else if (i == 1 && j == 2 && k == 0) m[4 / 4 + 4 * 4] = make_tuple(1, 2, 0);
				else if (i == 1 && j == 2 && k == 1) m[4 / 4 + 4 / 4] = make_tuple(1, 2, 1);
				else if (i == 1 && j == 2 && k == 2) m[4 / 4 + 4 + 4] = make_tuple(1, 2, 2);
				else if (i == 1 && j == 2 && k == 3) m[4 / 4 + 4 - 4] = make_tuple(1, 2, 3);
				else if (i == 1 && j == 3 && k == 0) m[4 / 4 - 4 * 4] = make_tuple(1, 3, 0);
				else if (i == 1 && j == 3 && k == 1) m[4 / 4 - 4 / 4] = make_tuple(1, 3, 1);
				else if (i == 1 && j == 3 && k == 2) m[4 / 4 - 4 + 4] = make_tuple(1, 3, 2);
				else if (i == 1 && j == 3 && k == 3) m[4 / 4 - 4 - 4] = make_tuple(1, 3, 3);
				else if (i == 2 && j == 0 && k == 0) m[4 + 4 * 4 * 4] = make_tuple(2, 0, 0);
				else if (i == 2 && j == 0 && k == 1) m[4 + 4 * 4 / 4] = make_tuple(2, 0, 1);
				else if (i == 2 && j == 0 && k == 2) m[4 + 4 * 4 + 4] = make_tuple(2, 0, 2);
				else if (i == 2 && j == 0 && k == 3) m[4 + 4 * 4 - 4] = make_tuple(2, 0, 3);
				else if (i == 2 && j == 1 && k == 0) m[4 + 4 / 4 * 4] = make_tuple(2, 1, 0);
				else if (i == 2 && j == 1 && k == 1) m[4 + int(4 / 4 / 4)] = make_tuple(2, 1, 1);
				else if (i == 2 && j == 1 && k == 2) m[4 + 4 / 4 + 4] = make_tuple(2, 1, 2);
				else if (i == 2 && j == 1 && k == 3) m[4 + 4 / 4 - 4] = make_tuple(2, 1, 3);
				else if (i == 2 && j == 2 && k == 0) m[4 + 4 + 4 * 4] = make_tuple(2, 2, 0);
				else if (i == 2 && j == 2 && k == 1) m[4 + 4 + 4 / 4] = make_tuple(2, 2, 1);
				else if (i == 2 && j == 2 && k == 2) m[4 + 4 + 4 + 4] = make_tuple(2, 2, 2);
				else if (i == 2 && j == 2 && k == 3) m[4 + 4 + 4 - 4] = make_tuple(2, 2, 3);
				else if (i == 2 && j == 3 && k == 0) m[4 + 4 - 4 * 4] = make_tuple(2, 3, 0);
				else if (i == 2 && j == 3 && k == 1) m[4 + 4 - 4 / 4] = make_tuple(2, 3, 1);
				else if (i == 2 && j == 3 && k == 2) m[4 + 4 - 4 + 4] = make_tuple(2, 3, 2);
				else if (i == 2 && j == 3 && k == 3) m[4 + 4 - 4 - 4] = make_tuple(2, 3, 3);
				else if (i == 3 && j == 0 && k == 0) m[4 - 4 * 4 * 4] = make_tuple(3, 0, 0);
				else if (i == 3 && j == 0 && k == 1) m[4 - 4 * 4 / 4] = make_tuple(3, 0, 1);
				else if (i == 3 && j == 0 && k == 2) m[4 - 4 * 4 + 4] = make_tuple(3, 0, 2);
				else if (i == 3 && j == 0 && k == 3) m[4 - 4 * 4 - 4] = make_tuple(3, 0, 3);
				else if (i == 3 && j == 1 && k == 0) m[4 - 4 / 4 * 4] = make_tuple(3, 1, 0);
				else if (i == 3 && j == 1 && k == 1) m[4 - int(4 / 4 / 4)] = make_tuple(3, 1, 1);
				else if (i == 3 && j == 1 && k == 2) m[4 - 4 / 4 + 4] = make_tuple(3, 1, 2);
				else if (i == 3 && j == 1 && k == 3) m[4 - 4 / 4 - 4] = make_tuple(3, 1, 3);
				else if (i == 3 && j == 2 && k == 0) m[4 - 4 + 4 * 4] = make_tuple(3, 2, 0);
				else if (i == 3 && j == 2 && k == 1) m[4 - 4 + 4 / 4] = make_tuple(3, 2, 1);
				else if (i == 3 && j == 2 && k == 2) m[4 - 4 + 4 + 4] = make_tuple(3, 2, 2);
				else if (i == 3 && j == 2 && k == 3) m[4 - 4 + 4 - 4] = make_tuple(3, 2, 3);
				else if (i == 3 && j == 3 && k == 0) m[4 - 4 - 4 * 4] = make_tuple(3, 3, 0);
				else if (i == 3 && j == 3 && k == 1) m[4 - 4 - 4 / 4] = make_tuple(3, 3, 1);
				else if (i == 3 && j == 3 && k == 2) m[4 - 4 - 4 + 4] = make_tuple(3, 3, 2);
				else if (i == 3 && j == 3 && k == 3) m[4 - 4 - 4 - 4] = make_tuple(3, 3, 3);
			}
		}
	}
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		map::const_iterator it = m.find(n);
		if (it == m.end()) {
			cout << "no solution\n";
		} else {
			int a, b, c;
			tie(a, b, c) = it->second;
			cout << 4;
			switch (a) {
			case 0: cout << " * "; break;
			case 1: cout << " / "; break;
			case 2: cout << " + "; break;
			case 3: cout << " - "; break;
			}
			cout << 4;
			switch (b) {
			case 0: cout << " * "; break;
			case 1: cout << " / "; break;
			case 2: cout << " + "; break;
			case 3: cout << " - "; break;
			}
			cout << 4;
			switch (c) {
			case 0: cout << " * "; break;
			case 1: cout << " / "; break;
			case 2: cout << " + "; break;
			case 3: cout << " - "; break;
			}
			cout << 4 << " = " << n << endl;;
		}
	}
}
