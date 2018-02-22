// https://open.kattis.com/problems/filip
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  istringstream ina(s);
  istringstream inb(t);
  int a, b;
  ina >> a;
  inb >> b;
  cout << max(a, b) << endl;
}
