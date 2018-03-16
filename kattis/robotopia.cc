// https://open.kattis.com/problems/robotopia
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	while (n--) {
		ll l1, a1, l2, a2, lt, at, x, y, c = 0;
		cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
		for (int i = 1; i <= 10000; i++) {
			int y1 = lt - l1 * i;
			int y2 = at - a1 * i;
			if (!(y1 % l2) && !(y2 % a2)) {
				y1 /= l2;
				y2 /= a2;
				if (y1 >= 1 && y1 == y2) {
					c++;
					if (c > 1) break;
					x = i;
					y = y1;
				}
			}
		}
		if (c == 1) cout << x << " " << y << endl;
		else cout << "?\n";
	}
}
