// https://uva.onlinejudge.org/external/3/394.pdf
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_map<string, vi> msi;

int main() {
	int n, r;
	cin >> n >> r;
	msi m;
	for (int i = 0; i < n; i++) {
		string name;
		int b, s, d;
		cin >> name >> b >> s >> d;
		vi l(d);
		vi u(d);
		for (int j = 0; j < d; j++) cin >> l[j] >> u[j];
		vi c(d + 1);
		c[d] = s;
		for (int j = d - 1; j >= 1; j--) c[j] = c[j+1] * (u[j]-l[j]+1);
		c[0] = b;
		for (int j = 1; j <= d; j++) c[0] -= c[j]*l[j - 1];
		m[name] = c;
	}
	for (int i = 0; i < r; i++) {
		string name;
		cin >> name;
		vi c = m[name];
		int sum = c[0];
		cout << name << "[";
		for (int j = 1; j < c.size(); j++) {
			int x;
			cin >> x;
			cout << x;
			if (j < c.size() - 1) cout << ", ";
			else cout << "] = ";
			sum += c[j] * x;
		}
		cout << sum << endl;
	}
}
