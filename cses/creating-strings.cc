// https://cses.fi/problemset/task/1622/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  vector<string> r;
  do r.push_back(s); while (next_permutation(s.begin(), s.end()));
  cout << r.size() << "\n";
  for (string &s : r) cout << s << "\n";
}
