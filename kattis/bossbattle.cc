// https://open.kattis.com/problems/bossbattle
#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 2;
	int b = n - 1;
	int c = 1;
	while (a < b) {
		a += 2;
		b++;
		c++;
	}
	cout << c << endl;
}
