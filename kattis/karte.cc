// https://open.kattis.com/problems/karte
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<vector<bool>> v(4);
  for (int i = 0; i < 4; i++) v[i] = vector<bool>(13, false);
  for (int i = 0; i < s.size(); i += 3) {
    char suit = s[i];
    int n = (s[i + 1] - '0') * 10 + s[i + 2] - '0' - 1;
    int k;
    switch (suit) {
      case 'P': k = 0; break;
      case 'K': k = 1; break;
      case 'H': k = 2; break;
      case 'T': k = 3;
    }
    if (v[k][n]) {
      cout << "GRESKA\n";
      return 0;
    }
    v[k][n] = true;
  }
  for (int i = 0; i < 4; i++) {
    int c = 0;
    for (int j = 0; j < 13; j++) {
      if (!v[i][j]) c++;
    }
    cout << c;
    if (i < 3) cout << " ";
    else cout << endl;
  }
}
