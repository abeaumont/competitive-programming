// https://open.kattis.com/problems/isithalloween
#include <bits/stdc++.h>

using namespace std;

int main() {
  string m;
  int d;
  cin >> m >> d;
  if ((m == "OCT" && d == 31) || (m == "DEC" && d == 25)) cout << "yup\n";
  else
    cout << "nope\n";
}
