// https://open.kattis.com/problems/ladder
#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int h, v;
	cin >> h >> v;
	cout << ceil(h / cos((90 - v) * M_PI / 180.0)) << endl;
}
