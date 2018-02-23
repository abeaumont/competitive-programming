// https://open.kattis.com/problems/pet
#include <iostream>

using namespace std;

int main() {
  int m = 0;
  int k;
  for (int i = 0; i < 5; i++) {
    int s = 0;
    for (int j = 0; j < 4; j++) {
      int x;
      cin >> x;
      s += x;
    }
    if (s > m) {
      m = s;
      k = i + 1;
    }
  }
  cout << k << " " << m << endl;
}
