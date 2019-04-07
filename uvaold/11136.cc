// http://uva.onlinejudge.org/external/111/11136.pdf
#include <iostream>
#include <set>

using namespace std;

int main() {
	while (true) {
		int n;
		cin >> n;
		if (!n) break;
		multiset<int> s;
		long long c = 0;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				int x;
				cin >> x;
				s.insert(x);
			}
			auto a = s.begin();
			auto b = s.rbegin();
			c += *b - *a;
			s.erase(a);
			s.erase(s.find(*b));
			}
		cout << c << endl;
	}
}
