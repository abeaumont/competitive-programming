// https://open.kattis.com/problems/iboard
#include <iostream>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		int o = 0, z = 0;
		for (char c:s) {
			int k = 0;
			for (int i = 0; i < 7; i++) k += ((1 << i) & c) != 0;
			o += k;
			z += 7 - k;
		}
		if (o % 2 || z % 2) cout << "trapped\n";
		else cout << "free\n";
	}
}
