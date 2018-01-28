// https://open.kattis.com/problems/guess
#include <iostream>

using namespace std;

int main() {
  int a = 1;
  int b = 1000;
  while (true) {
    int t = (a + b) / 2;
    cout << t << endl;;
    string r;
    cin >> r;
    if (r == "correct") break;
    if (r == "lower") b = t - 1;
    else a = t + 1;
  }
}
