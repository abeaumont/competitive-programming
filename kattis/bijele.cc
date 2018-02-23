// https://open.kattis.com/problems/bijele
#include <iostream>

using namespace std;

int main() {
  int expected[6] = {1, 1, 2, 2, 2, 8};
  for (int i = 0; i < 6; i++) {
    int x;
    cin >> x;
    cout << expected[i] - x;
    if (i < 6) cout << " ";
  }
  cout << endl;
}
