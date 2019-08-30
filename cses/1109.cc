// https://cses.fi/problemset/task/1109/
#include <iostream>

using namespace std;

int x, y, n, a[1000001];

int main() {
  string s;
  cin >> s;
  n = s.size();
  int i = 1;
  for (;i < n; i++) {
    a[i] = max(0, min(a[i - x], y - i + 1));
    while (a[i] + i < n && s[a[i]] == s[a[i] + i]) {
      x = i; y = a[i] + i; a[i]++;
    }
    if (i + a[i] == n) break;
  }
  cout << s.substr(i, a[i]) << endl;
}
