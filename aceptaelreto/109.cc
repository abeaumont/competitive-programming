// https://www.aceptaelreto.com/problem/statement.php?id=109
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s, n1, n2;
  int k1, k2, s1, s2;
  while (1) {
    getline(cin, s);
    if (s == "FIN") break;
    unordered_map<string, int> m;
    vector<string> names;
    vector<int> wins;
    int c = 0;
    getline(cin, s);
    while (s != "FIN") {
      c++;
      stringstream in(s);
      in >> n1 >> s1 >> n2 >> s2;
      auto it = m.find(n1);
      if (it == m.end()) {
        k1 = names.size();
        m[n1] = k1;
        names.push_back(n1);
        wins.push_back(0);
      } else
        k1 = it->second;
      it = m.find(n2);
      if (it == m.end()) {
        k2 = names.size();
        m[n2] = k2;
        names.push_back(n2);
        wins.push_back(0);
      } else
        k2 = it->second;
      if (s2 > s1) swap(k1, k2);
      wins[k1] += 2;
      wins[k2]++;
      getline(cin, s);
    }
    int mx = wins[0], mxi = 0, mxdup = 0;
    for (int i = 1; i < wins.size(); i++)
      if (wins[i] > mx) mx = wins[i], mxi = i, mxdup = 0;
      else if (wins[i] == mx)
        mxdup = 1;
    cout << (mxdup ? "EMPATE" : names[mxi]) << ' '
         << names.size() * (names.size() - 1) - c << '\n';
  }
}
