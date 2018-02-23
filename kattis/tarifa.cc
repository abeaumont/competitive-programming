// https://open.kattis.com/problems/tarifa
#include <iostream>

using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    sum += p;
  }
  cout << ((n + 1) * x - sum) << endl;
}
