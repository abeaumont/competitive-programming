// https://open.kattis.com/problems/pauleigon
#include <iostream>

using namespace std;

int main() {
  int n, p, q;
  cin >> n >> p >> q;
  cout << (((p + q) / n) % 2 ? "opponent\n" : "paul\n");
}
