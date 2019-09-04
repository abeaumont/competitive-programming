// https://www.aceptaelreto.com/problem/statement.php?id=442
#include<bits/stdc++.h>
using namespace std;
int main() {
  for (;;) {
    string a, b, s, r;
    getline(cin, s);
    if (s.empty()) break;
    stringstream in(s);
    in >> a >> b;
    vector<string> w;
    int i = 0, j = 1;
    if (a[0] >= 'A' && a[0] <= 'Z') {
      while (j <= a.size()) {
        while (j < a.size() && a[j] >= 'a' && a[j] <= 'z') j++;
        a[i] += 32;
        w.push_back(a.substr(i, j - i));
        i = j, j++;
      }
    } else {
      while (j <= a.size()) {
        while (j < a.size() && a[j] != '-' && a[j] != '_') j++;
        w.push_back(a.substr(i, j - i));
        i = j + 1, j += 2;
      }
    }
    if (b == "snake_case")
      for (int i = 0; i < w.size(); i++)
        cout << w[i] << "_\n"[i == w.size() - 1];
    else if (b == "kebab-case")
      for (int i = 0; i < w.size(); i++)
        cout << w[i] << "-\n"[i == w.size() - 1];
    else {
      for (int i = 0; i < w.size(); i++) {
        w[i][0] -= 32;
        cout << w[i];
      }
      cout << endl;
    }
  }
}
