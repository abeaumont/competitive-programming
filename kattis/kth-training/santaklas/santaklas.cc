// https://open.kattis.com/problems/santaklas
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int h, v;
  cin >> h >> v;
  if (v <= 180) cout << "safe\n";
  else cout << int(h / sin((v - 180) * M_PI / 180)) << endl;
}
