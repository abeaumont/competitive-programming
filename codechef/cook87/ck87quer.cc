// https://www.codechef.com/COOK87/problems/CK87QUER
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long x;
		cin >> x;
		int s = 0;
		for (long long j = sqrt(x); j >= 1; j--) {
			if (j * j >= x) continue;
			long long diff = x - j * j;
			if (diff >= 700) {
				s += j * 700;
				break;
			}
			s += diff;
		}
		cout << s << endl;
	}
}
