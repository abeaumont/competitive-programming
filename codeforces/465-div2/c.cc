// http://codeforces.com/contest/935/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef complex<double> p;

int main() {
	double R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	p p1 = {x1, y1};
	p p2 = {x2, y2};
	p p3 = p1 - p2;
	double d = abs(p3);
	cout << fixed << setprecision(17) ;
	if (p1 == p2) cout << x1 + R/2 << " " << y1 << " " << R/2 << endl;
	else if (d >= R) cout << x1 << " " << y1 << " " << R << endl;
	else {
		double r = (d + R) / 2;
		p1 += p3/d * ((R - d) / 2);
		cout << p1.real() << " " << p1.imag() << " " << r << endl;
	}
}
