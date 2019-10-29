// https://open.kattis.com/problems/trendingtopic
#include <bits/stdc++.h>

using namespace std;
using is = tuple<int, string>;

int f[20001];

int main() {
  unordered_map<string, int> m;
  vector<string> mi;
  queue<tuple<int, int>> q;
  int i = 0, d = 0;
	while (!cin.eof()) {
		string s;
    cin >> s;
    if (s.size() < 4 || s == "</text>") continue;
    if (s == "<text>") {
      d++;
      while (!q.empty()) {
        int k, t;
        tie(k, t) = q.front();
        if (k > d - 7) break;
        f[t]--;
        q.pop();
      }
    } else if (s == "<top") {
      int n;
      cin >> n >> s;
      cout << "<top " << n << ">\n";
      if (n > i) n = i;
      vector<is> a(i);
      for (int k = 0; k < i; k++)
        a[k] = {f[k], mi[k]};
      sort(a.begin(), a.end(), [](is &a, is&b) { return get<0>(a) > get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b)); });
      int l = get<0>(a[n - 1]);
      for (is &x : a) {
        int k; string s;
        tie(k, s) = x;
        if (k < l) break;
        cout << s << " " << k << "\n";
      }
      cout << "</top>\n";
    } else {
      if (!m.count(s)) m[s] = i++, mi.push_back(s);
      int k = m[s];
      f[k]++;
      q.push({d, k});
    }
  }
}
