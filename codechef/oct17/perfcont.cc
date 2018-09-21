// https://www.codechef.com/OCT17/problems/PERFCONT/
#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, p;
		cin >> n >> p;
		int a = 0;
		int b = 0;
		for (int j = 0; j < n; j++) {
			int s;
			cin >> s;
			if (s >= p / 2) a++;
			if (s <= p / 10) b++;
		}
		cout << (a == 1 && b == 2 ? "yes" : "no") << endl;
	}
}
