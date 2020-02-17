// https://open.kattis.com/problems/onechicken
#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  if (m > n) {
    if (m - n == 1) cout << "Dr. Chaz will have 1 piece of chicken left over!\n";
    else cout << "Dr. Chaz will have " << m - n << " pieces of chicken left over!\n";
  } else {
    if (n - m == 1) cout << "Dr. Chaz needs 1 more piece of chicken!\n";
    else cout << "Dr. Chaz needs " << n - m << " more pieces of chicken!\n";
  }
}
