// https://www.aceptaelreto.com/problem/statement.php?id=106
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  string s;
  while (1) {
    cin >> s;
    if (s.size() == 1 && s[0] == '0') break;
    int sum = 0;
    for (int i = s.size() - 1, j = 0; i >= 0; i--, j++)
      sum += (s[i] - '0') * (j % 2 ? 3 : 1);
    bool ok = sum % 10 == 0;
    cout << (ok ? "SI" : "NO");
    if (ok && s.size() > 8) {
      string c = "Desconocido";
      if (s.size() < 13) c = "EEUU";
      else {
        if (s[0] == '0') c = "EEUU";
        else if (s.substr(0, 3) == "380")
          c = "Bulgaria";
        else if (s.substr(0, 2) == "50")
          c = "Inglaterra";
        else if (s.substr(0, 3) == "539")
          c = "Irlanda";
        else if (s.substr(0, 3) == "560")
          c = "Portugal";
        else if (s.substr(0, 2) == "70")
          c = "Noruega";
        else if (s.substr(0, 3) == "759")
          c = "Venezuela";
        else if (s.substr(0, 3) == "850")
          c = "Cuba";
        else if (s.substr(0, 3) == "890")
          c = "India";
      }
      cout << ' ' << c;
    }
    cout << '\n';
  }
}
