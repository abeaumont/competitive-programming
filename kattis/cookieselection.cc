// https://open.kattis.com/problems/cookieselection
#include <iostream>
#include <sstream>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
	string l;
	indexed_set s;
	while ((cin >> l)) {
		if (l == "#") {
			auto it = s.find_by_order(s.size() % 2 ? (s.size() + 1) / 2 - 1 : s.size() / 2);
			cout << *it << endl;
			s.erase(it);
			continue;
		}
		stringstream in(l);
		int x;
		in >> x;
		s.insert(x);
	}
}
