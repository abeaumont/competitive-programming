// https://open.kattis.com/problems/modulo
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<int> s;
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		s.insert(x % 42);
	}
	cout << s.size() << endl;
}
