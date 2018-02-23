// https://open.kattis.com/problems/mixedfractions
#include <iostream>

using namespace std;

int main() {
  while (true) {
    int n, d;
    cin >> n >> d;
    if (n == 0 && d == 0) break;
    int q = n / d;
    cout << q << " " << n - q * d << " / " << d << endl;
  }
}
