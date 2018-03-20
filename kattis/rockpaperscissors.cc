// https://open.kattis.com/problems/rockpaperscissors
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
	bool first = true;
	cout << fixed << setprecision(3);
	while (true) {
		int n, k;
		cin >> n;
		if (!n) break;
		cin >> k;
		vi w(n, 0);
		vi l(n, 0);
		for (int i = 0; i < k * n * (n - 1) / 2; i++) {
			int p1, p2;
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			if (m1 == m2) continue;
			else if (m1 == "paper" && m2 == "rock") {
				w[p1 - 1]++;
				l[p2 - 1]++;
			} else if (m1 == "rock" && m2 == "paper") {
				w[p2 - 1]++;
				l[p1 - 1]++;
			} else if (m1 == "scissors" && m2 == "paper") {
				w[p1 - 1]++;
				l[p2 - 1]++;
			} else if (m1 == "paper" && m2 == "scissors") {
				w[p2 - 1]++;
				l[p1 - 1]++;
			} else if (m1 == "rock" && m2 == "scissors") {
				w[p1 - 1]++;
				l[p2 - 1]++;
			} else if (m1 == "scissors" && m2 == "rock") {
				w[p2 - 1]++;
				l[p1 - 1]++;
			}
		}
		if (first) first = false;
		else cout << endl;
		for (int i = 0; i < n; i++) {
			if (!(w[i] + l[i])) cout << "-";
			else cout << double(w[i]) / (w[i] + l[i]);
			cout << endl;
		}
	}
}
