// https://cses.fi/problemset/stats/1624/
#include <bits/stdc++.h>

using namespace std;

vector<int> b;
string a[8];
int c;

void f(int i) {
  if (i == 8) {
    c++;
    return;
  }
  for (int j = 0; j < 8; j++) {
    if (a[i][j] == '*') continue;
    bool ok = true;
    for (int k = 0; k < i; k++)
      if (b[k] == j || b[k] == j + (i - k) || b[k] == j - (i - k)) {
        ok = false;
        break;
      }
    if (!ok) continue;
    b.push_back(j);
    f(i + 1);
    b.pop_back();
  }
}

int main() {
  for (int i = 0; i < 8; i++) cin >> a[i];
  f(0);
  cout << c << endl;
}
