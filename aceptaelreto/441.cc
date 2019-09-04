// https://www.aceptaelreto.com/problem/statement.php?id=441
#include <bits/stdc++.h>
using namespace std;
int main() {
  for (;;) {
    string s;
    getline(cin, s);
    if (s.empty()) break;
    vector<int> a;
    for(int i = s.size() - 1; i >= 0; i--)
      if(s[i] != '.' && s[i] != '-')
        a.push_back(s[i] - '0');
    int c = 1;
    if (s[0] == '-') {
      for (int i = 0; i < a.size(); i++) {
        a[i] -= c;
        if (a[i] < 0) c = 1, a[i] += 10;
        else c = 0;
      }
      while (a.size() && a.back() == 0) a.pop_back();
      if (a.size()) {
        cout << "-";
        for (int i = a.size() - 1; i >= 0; i--) {
          cout << a[i];
          if (i && !(i % 3)) cout << ".";
        }
        cout << "\n";
      } else cout << "0\n";
    } else {
      for (int i = 0; i < a.size(); i++) {
        a[i] += c;
        if (a[i] > 9) c = 1, a[i] -= 10;
        else c = 0;
      }
      if (c) a.push_back(c);
      for (int i = a.size() - 1; i >= 0; i--) {
        cout << a[i];
        if (i && !(i % 3)) cout << ".";
      }
      cout << "\n";
    }
  }
}
