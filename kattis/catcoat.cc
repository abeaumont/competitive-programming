// https://open.kattis.com/problems/catcoat
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	pair<int, int> sb, sr, sd, tb, tr, td;
	if (s == "Black") {
		sb = {3, 1};
		sr = {0, 1};
		sd = {3, 1};
	} else if (s == "Blue") {
		sb = {3, 1};
		sr = {0, 1};
		sd = {0, 1};
	} else if (s == "Chocolate") {
		sb = {0, 1};
		sr = {0, 1};
		sd = {3, 1};
	} else if (s == "Lilac") {
		sb = {0, 1};
		sr = {0, 1};
		sd = {0, 1};
	} else if (s == "Red") {
		sb = {1, 1};
		sr = {1, 0};
		sd = {3, 1};
	} else if (s == "Cream") {
		sb = {1, 1};
		sr = {1, 0};
		sd = {0, 1};
	} else if (s == "Black-Red Tortie") {
		sb = {3, 1};
		sr = {1, 1};
		sd = {3, 1};
	} else if (s == "Blue-Cream Tortie") {
		sb = {3, 1};
		sr = {1, 1};
		sd = {0, 1};
	} else if (s == "Chocolate-Red Tortie") {
		sb = {0, 1};
		sr = {1, 1};
		sd = {3, 1};
	} else {
		sb = {0, 1};
		sr = {1, 1};
		sd = {0, 1};
	}
	if (t == "Black") {
		tb = {3, 1};
		tr = {0, 1};
		td = {3, 1};
	} else if (t == "Blue") {
		tb = {3, 1};
		tr = {0, 1};
		td = {0, 1};
	} else if (t == "Chocolate") {
		tb = {0, 1};
		tr = {0, 1};
		td = {3, 1};
	} else if (t == "Lilac") {
		tb = {0, 1};
		tr = {0, 1};
		td = {0, 1};
	} else if (t == "Red") {
		tb = {1, 1};
		tr = {1, 0};
		td = {3, 1};
	} else  {
		tb = {1, 1};
		tr = {1, 0};
		td = {0, 1};
	}
	double x[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	double q = (sb.first + sb.second) * (sr.first + sr.second) * (sd.first + sd.second) *
		(tb.first + tb.second) * (tr.first + tr.second) * (td.first + td.second);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					for (int m = 0; m < 2; m++)
						for (int n = 0; n < 2; n++) {
							int p = (i ? sb.second : sb.first) * (j ? sr.second : sr.first) *
								(k ? sd.second : sd.first) * (l ? tb.second : tb.first) *
								(m ? tr.second : tr.first) * (n ? td.second : td.first);
							if (!p) continue;
							if ((i == 0 || l == 0) && j == 1 && m == 1 && (k == 0 || n == 0)) x[0] += p / q;
							else if ((i == 0 || l == 0) && j == 1 && m == 1 && k == 1 && n == 1) x[1] += p / q;
							else if (i == 1 && l == 1 && j == 1 && m == 1 && (k == 0 || n == 0)) x[2] += p / q;
							else if (i == 1 && l == 1 && j == 1 && m == 1 && k == 1 && n == 1) x[3] += p / q;
							else if (j == 0 && m == 0 && (k == 0 || n == 0)) x[4] += p / q;
							else if (j == 0 && m == 0 && k == 1 && n == 1) x[5] += p / q;
							else if ((i == 0 || l == 0) && j == 1 && m == 0 && (k == 0 || n == 0)) {
								x[0] += p / (q * 2);
								x[6] += p / (q * 2);
							} else if ((i == 0 || l == 0) && j == 1 && m == 0 && k == 1 && n == 1) {
								x[1] += p / (q * 2);
								x[7] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 1 && m == 0 && (k == 0 || n == 0)) {
								x[2] += p / (q * 2);
								x[8] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 1 && m == 0 && k == 1 && n == 1) {
								x[3] += p / (q * 2);
								x[9] += p / (q * 2);
							} else if ((i == 0 || l == 0) && j == 0 && m == 1 && (k == 0 || n == 0)) {
								x[4] += p / (q * 2);
								x[6] += p / (q * 2);
							} else if ((i == 0 || l == 0) && j == 0 && m == 1 && k == 1 && n == 1) {
								x[5] += p / (q * 2);
								x[7] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 0 && m == 1 && (k == 0 || n == 0)) {
								x[4] += p / (q * 2);
								x[8] += p / (q * 2);
							} else if (i == 1 && l == 1 && j == 0 && m == 1 && k == 1 && n == 1) {
								x[5] += p / (q * 2);
								x[9] += p / (q * 2);
							}
						}
	string n[10] = {"Black", "Blue", "Chocolate", "Lilac", "Red", "Cream",
									"Black-Red Tortie", "Blue-Cream Tortie",
									"Chocolate-Red Tortie", "Lilac-Cream Tortie"};
	vector<pair<double, string>> v;
	for (int i = 0; i < 10; i++)
		if (x[i]) v.push_back({-x[i], n[i]});
	sort(v.begin(), v.end());
	for (auto z : v) cout << z.second << " " << fixed << setprecision(9) << -z.first << endl;
}
