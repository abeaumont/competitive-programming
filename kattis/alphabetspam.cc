// https://open.kattis.com/problems/alphabetspam
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	int a, b, c, d;
	a = b = c = d = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '_') a++;
		else if (s[i] >= 'a' && s[i] <= 'z') b++;
		else if (s[i] >= 'A' && s[i] <= 'Z') c++;
		else d++;
	}
	double t = a + b + c + d;
	cout << setprecision(10) << fixed
			 << double(a) / t << endl
			 << double(b) / t << endl
			 << double(c) / t << endl
			 << double(d) / t << endl;
}
