// https://open.kattis.com/problems/abc
#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string s;
  cin >> s;
  int x = s[0] - 'A';
  int y = s[1] - 'A';
  int z = s[2] - 'A';
  int m1 = min(a, min(b, c));
  int m3 = max(a, max(b, c));
  int m2 = a;
  if (m2 == m1 || m2 == m3) {
    m2 = b;
    if (m2 == m1 || m2 == m3) m2 = c;
  }
  if (x == 0) cout << m1;
  else if (x == 1) cout << m2;
  else cout << m3;
  cout << " ";
  if (y == 0) cout << m1;
  else if (y == 1) cout << m2;
  else cout << m3;
  cout << " ";
  if (z == 0) cout << m1;
  else if (z == 1) cout << m2;
  else cout << m3;
  cout << endl;
}
