// https://open.kattis.com/problems/bus
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int x = 1;
    for (int j = 0; j < n; j++) {
      x *= 2;
    }
    cout << x - 1 << endl;
  }
}
