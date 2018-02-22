// https://open.kattis.com/problems/faktor
#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  cout << a * (b - 1) + 1 << endl;
}
