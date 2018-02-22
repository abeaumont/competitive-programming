// https://open.kattis.com/problems/humancannonball2
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double v, t, x, h1, h2;
		cin >> v >> t >> x >> h1 >> h2;
		t = t * M_PI / 180.0;
		double time = x / (v * cos(t));
		double y = v * time * sin(t) - 9.81 * time * time / 2 ;
		if (y >= h1 + 1 && y <= h2 - 1) cout << "Safe\n";
		else cout << "Not Safe\n";
	}
}
