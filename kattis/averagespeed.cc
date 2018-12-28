// https://open.kattis.com/problems/averagespeed
#include <iostream>

using namespace std;

int main() {
	string l;
	double d = 0;
	while (cin >> l) {
		int h, m, s, k, p = -1, q;
		if (s.size() > 8) {
			sscanf(l.c_str(), "%d:%d:%d %d\n", &h, &m, &s, &k);
			int a = h * 3600 + m * 60 + s;
			if (p >= 0) {
				d += (a - p) * double(q) / 3.6;
			}
			p = a;
			q = k;
		} else {
			sscanf(l.c_str(), "%d:%d:%d\n", &h, &m, &s, &k)
		}
	}
}
