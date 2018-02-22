// https://open.kattis.com/problems/kornislav
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int x[4];
  for (int i = 0; i < 4; i++) cin >> x[i];
  sort(x, x+4);
  cout << x[0] * x[2] << endl;
}
