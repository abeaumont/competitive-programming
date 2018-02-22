// https://open.kattis.com/problems/listgame
#include <cmath>
#include <iostream>

using namespace std;

int divisors(int x) {
  int c = 0;
  while (x > 1) {
    bool found = false;
    for (int i = 2; i <= sqrt(x); i++) {
      if (x % i == 0) {
        c++;
        x /= i;
        found = true;
        break;
      }
    }
    if (!found) {
      c++;
      break;
    }
  }
  return c++;
}

int main() {
  int x;
  cin >> x;
  cout << divisors(x) << endl;
}
