// https://www.aceptaelreto.com/problem/statement.php?id=102
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    string s;
    getline(cin, s);
    int rot = ('p' - s[0]);
    if (rot < 0) rot += 26;
    int count = 0;
    for (int i = 1; i < s.size(); i++) {
      char base = 0;
      if (s[i] >= 'a' && s[i] <= 'z') base = 'a';
      else if (s[i] >= 'A' && s[i] <= 'Z')
        base = 'A';
      if (!base) continue;
      char c = ((s[i] - base) + rot) % 26;
      if (c < 0) c += 26;
      if (c == 0 || c == 4 || c == 8 || c == 14 || c == 20) count++;
      c += base;
      s[i] = c;
    }
    if (s.size() == 4 && s.substr(1, 3) == "FIN") break;
    cout << count << '\n';
  }
}
