// https://open.kattis.com/problems/inversefactorial
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s == "1") cout << "1\n";
  else if (s == "2")
    cout << "2\n";
  else if (s == "6")
    cout << "3\n";
  else if (s == "24")
    cout << "4\n";
  else if (s == "120")
    cout << "5\n";
  else if (s == "720")
    cout << "6\n";
  else {
    double digits = 0;
    int i = 2;
    while (int(digits) < s.size()) digits += log10(double(i++));
    cout << i - 2 << '\n';
  }
}
