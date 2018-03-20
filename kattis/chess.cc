// https://open.kattis.com/problems/chess
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int y1, y2;
		char c1, c2;
		cin >> c1 >> y1 >> c2 >> y2;
		int x1 = c1 - 'A';
		int x2 = c2 - 'A';
		y1--;
		y2--;
		if ((x1 + y1) % 2 != (x2 + y2) % 2) {
			cout << "Impossible\n";
			continue;
		}
		if (x1 == x2 && y1 == y2) {
			cout << 0 << " " << c1 << " " << y1 + 1 << " " << c2 << " " << y2 + 1 << endl;
			continue;
		}
		int b[8][8];
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				b[i][j] = 0;
		for (int i = 0; i < 8; i++) {
			if (x1 + i < 8 && y1 + i < 8) b[x1 + i][y1 + i] = 1;
			if (x1 + i < 8 && y1 - i >= 0) b[x1 + i][y1 - i] = 1;
			if (x1 - i >= 0 && y1 + i < 8) b[x1 - i][y1 + i] = 1;
			if (x1 - i >= 0 && y1 - i >= 0) b[x1 - i][y1 - i] = 1;
		}
		int x, y;
		for (int i = 0; i < 8; i++) {
			if (x2 + i < 8 && y2 + i < 8 && b[x2 + i][y2 + i]) {
				x = x2 + i;
				y = y2 + i;
				break;
			}
			if (x2 + i < 8 && y2 - i >= 0 && b[x2 + i][y2 - i]) {
				x = x2 + i;
				y = y2 - i;
				break;
			}
			if (x2 - i >= 0 && y2 + i < 8 && b[x2 - i][y2 + i]) {
				x = x2 - i;
				y = y2 + i;
				break;
			}
			if (x2 - i >= 0 && y2 - i >= 0 && b[x2 - i][y2 - i]) {
				x = x2 - i;
				y = y2 - i;
				break;
			}
		}
		if (x == x1 && y == y1 || x == x2 && y == y2) {
			cout << 1 << " " << c1 << " " << y1 + 1 << " " << c2 << " " << y2 + 1 << endl;
			continue;
		}
		cout << 2 << " " << c1 << " " << y1 + 1 << " " << char('A' + x) << " " << y + 1 << " " << c2 << " " << y2 + 1 << endl;
	}
}
