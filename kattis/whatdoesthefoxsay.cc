// https://open.kattis.com/problems/whatdoesthefoxsay
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<char*> vs;
typedef unordered_map<string, int> map;

int main() {
	int t;
	string s;
	cin >> t;
	getline(cin, s);
	for (int i = 0; i < t; i++) {
		getline(cin, s);
		istringstream in(s);
		vi v;
		string as[100];
		int index = 0;
		map xs;
		while (true) {
			if (in.eof()) break;
			string x;
			in >> x;
			map::iterator it = xs.find(x);
			if (it == xs.end()) {
				xs[x] = index;
				as[index] = x;
				v.push_back(index);
				index++;
			} else {
				v.push_back(it->second);
			}
		}
		vector<bool> y(100, 0);
		while (true) {
			char s1[101];
			char s2[101];
			char s3[101];
			scanf("%s %s %s", s1, s2, s3);
			if (!strncmp(s2, "does", 4)) {
				scanf("%s %s\n", s1, s2);
				break;
			}
			int arts = xs.find(s3)->second;
			y[arts] = true;
		}
		bool first = true;
		for (int i = 0; i < v.size(); i++) {
			if (!y[v[i]]) {
				if (first) {
					first = false;
				} else {
					cout << " ";
				}
				cout << as[v[i]];
			}
		}
		cout << endl;
	}
}
