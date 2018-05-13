// https://uva.onlinejudge.org/external/2/230.pdf
#include <iostream>
#include <map>

using namespace std;

struct cmp {
  bool operator() (const string& lhs, const string& rhs) const {return lhs>rhs;}
};

typedef pair<string, string> pss;
typedef multimap<string, string> mmss;
typedef multimap<string, string, cmp> mmssd;
typedef map<string, string> mss;

int main() {
	string s;
	mmssd shelve;
	mss titles;
	while (true) {
		getline(cin, s);
		if (s == "END") break;
		int c = 0;
		int i = 0;
		int spos = -1;
		while (i < s.size()) {
			if (s[i] == '"') {
				c++;
				if (c == 2) break;
				spos = i;
			}
			i++;
		}
		int epos = i++;
		string title = s.substr(spos + 1, epos - spos - 1);
		while (s[i] != 'b') i++;
		i++;
		while (s[i] != 'y') i++;
		i++;
		while (isspace(s[i])) i++;
		string author = s.substr(i, s.size() - i);
		shelve.insert(pss(author, title));
		titles[title] = author;
	}
	mmss returns;
	while (true) {
		getline(cin, s);
		if (s == "END") break;
		if (s[0] == 'B') {
			string title = s.substr(8, s.size() - 9);
			string author = titles.find(title)->second;
			mmssd::iterator it = shelve.lower_bound(author);
			while (true) {
				if (it->second == title) break;
				it++;
			}
			shelve.erase(it);
		}
		if (s[0] == 'R') {
			string title = s.substr(8, s.size() - 9);
			string author = titles.find(title)->second;
			returns.insert(pss(author, title));
			continue;
		}
		if (s[0] == 'S') {
			for (mmss::iterator it = returns.begin(); it != returns.end(); it++) {
				string author = it->first;
				string title = it->second;
				mmssd::iterator it2 = shelve.lower_bound(author);
				while (it2 != shelve.end()) {
					if (it2->first < author) break;
					if (it2->second < title) break;
					it2++;
				}
				if (it2 == shelve.end()) {
					cout << "Put \"" << title << "\" first\n";
				} else {
					cout << "Put \"" << title << "\" after \"" << it2->second << "\"\n";
				}
				shelve.insert(pss(author, title));
			}
			cout << "END\n";
			returns.clear();
		}
	}
}
