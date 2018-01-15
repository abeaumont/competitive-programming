// https://open.kattis.com/problems/2048
#include <iostream>

using namespace std;

int main() {
	int x[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> x[i][j];
	int a;
	cin >> a;
	switch (a) {
	case 0:
		for (int i = 0; i < 4; i++)
			for (int j = 1; j < 4; j++)
				for (int k = j; k >= 1; k--) {
					if (x[i][k] != 0 && x[i][k - 1] == 0) {
						x[i][k - 1] = x[i][k];
						x[i][k] = 0;
					} else break;
				}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++) {
				if (x[i][j] == x[i][j + 1]) {
					x[i][j] *= 2;
					for (int k = j + 1; k < 4; k++) {
						x[i][k] = x[i][k + 1];
					}
					x[i][3] = 0;
				}
			}
		break;
	case 1:
		for (int i = 1; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = i; k >= 1; k--) {
					if (x[k][j] != 0 && x[k - 1][j] == 0) {
						x[k - 1][j] = x[k][j];
						x[k][j] = 0;
					} else break;
				}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 4; j++) {
				if (x[i][j] == x[i + 1][j]) {
					x[i][j] *= 2;
					for (int k = i + 1; k < 4; k++) {
						x[k][j] = x[k + 1][j];
					}
					x[3][j] = 0;
				}
			}
		break;		
	case 2:
		for (int i = 0; i < 4; i++)
			for (int j = 2; j >= 0; j--)
				for (int k = j; k < 3; k++) {
					if (x[i][k] != 0 && x[i][k + 1] == 0) {
						x[i][k + 1] = x[i][k];
						x[i][k] = 0;
					} else break;
				}
		for (int i = 0; i < 4; i++)
			for (int j = 3; j > 0; j--) {
				if (x[i][j] == x[i][j - 1]) {
					x[i][j] *= 2;
					for (int k = j - 1; k >= 0; k--) {
						x[i][k] = x[i][k - 1];
					}
					x[i][0] = 0;
				}
			}
		break;
	case 3:
		for (int i = 2; i >= 0; i--)
			for (int j = 0; j < 4; j++)
				for (int k = i; k < 3; k++) {
					if (x[k][j] != 0 && x[k + 1][j] == 0) {
						x[k + 1][j] = x[k][j];
						x[k][j] = 0;
					} else break;
				}
		for (int i = 3; i > 0; i--)
			for (int j = 0; j < 4; j++) {
				if (x[i][j] == x[i - 1][j]) {
					x[i][j] *= 2;
					for (int k = i - 1; k >= 0; k--) {
						x[k][j] = x[k - 1][j];
					}
					x[0][j] = 0;
				}
			}
		break;		
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << x[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
}
