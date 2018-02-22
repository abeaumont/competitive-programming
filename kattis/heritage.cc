// https://open.kattis.com/problems/heritage
#include <iostream>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, int> map;
typedef long long ll;

const int P = 1000000007;
static ll cache[33];

ll c(const string &w, const map &m, int k) {
	if (cache[k]) return cache[k];
	auto s = w.substr(k);
	auto it = m.find(s);
	ll sum = 0;
	if (it != m.end()) sum += it->second;
	for (int i = 1; k + i < w.size(); i++) {
		s = w.substr(k, i);
		it = m.find(s);
		if (it != m.end()) sum = (sum + (it->second * c(w, m, k + i)) % P) % P;
	}
	cache[k] = sum;
	return sum;
}

int main() {
	int n;
	string w;
	cin >> n >> w;
	map m;
	for (int i = 0; i < n; i++) {
		string si;
		int ii;
		cin >> si >> ii;
		m[si] = ii;
	}
	cout << c(w, m, 0) << endl;
}
