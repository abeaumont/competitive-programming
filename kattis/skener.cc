// https://open.kattis.com/problems/skener
#include <bits/stdc++.h>

using namespace std;

int main() {
  int r, c, zr, zc;
  cin >> r >> c >> zr >> zc;
  while (r--) {
    string s;
    cin >> s;
    for (int i = 0; i < zr; i++) {
      for (char ch : s)
        for (int j = 0; j < zc; j++) cout << ch;
      cout << endl;
    }
  }
}
