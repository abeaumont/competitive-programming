// https://open.kattis.com/problems/sibice
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int n, w, h;
	cin >> n >> w >> h;
	int limit = sqrt(h * h + w * w);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cout << (x <= limit ? "DA" : "NE") << endl;
	}
}
