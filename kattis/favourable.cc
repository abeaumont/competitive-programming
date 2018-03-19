// https://open.kattis.com/problems/favourable
#include <iostream>
#include <sstream>

using namespace std;

typedef long long ll;

struct section {
	bool end;
	bool ok;
	int choices[3];
};

ll cache[401];

ll c(const section a[], int k) {
	if (a[k].end) return a[k].ok ? 1 : 0;
	if (cache[k] != -1) return cache[k];
	ll s = 0;
	for (int i = 0; i < 3; i++)
		s += c(a, a[k].choices[i]);
	cache[k] = s;
	return s;
}

int main() {
	int t;
	cin >> t;
	section a[401];
	while (t--) {
		for (int i = 0; i < 401; i++) cache[i] = -1;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int k;
			string s;
			cin >> k >> s;
			if (s[0] == 'f' || s[0] == 'c') a[k] = {true, s[0] == 'f', {0,0,0}};
			else {
				stringstream in(s);
				int x, y, z;
				in >> x;
				cin >> y >> z;
				a[k] = {false, false, {x, y, z}};
			}
		}
		cout << c(a, 1) << endl;
	}
}
