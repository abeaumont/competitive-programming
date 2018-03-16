// https://open.kattis.com/problems/datum
#include <iostream>

using namespace std;

int main() {
	int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string w[] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < 12; i++) d[i + 1] += d[i];
	int k = (d[b - 1] + a - 1) % 7;
	cout << w[k] << endl;
}
