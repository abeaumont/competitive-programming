// https://open.kattis.com/problems/lyklagangriti
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  list<char> ans;
  auto it = ans.begin();
  for (char c : s) switch (c) {
    case 'L': --it; break;
    case 'R': ++it; break;
    case 'B': it = ans.erase(--it); break;
    default: ans.insert(it, c); break;
    }
  for (auto it = ans.begin(); it != ans.end(); ++it) cout << *it;
  cout << '\n';
}
