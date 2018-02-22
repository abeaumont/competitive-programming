// https://open.kattis.com/problems/bela
#include <iostream>

using namespace std;

int main() {
  int n;
  char b;
  cin >> n >> b;
  int t = 0;
  for (int i = 0; i < 4 * n; i++) {
    string r;
    cin >> r;
    char c = r[0];
    char s = r[1];
    switch(c) {
      case 'A': t += 11; break;
      case 'K': t += 4; break;
      case 'Q': t += 3; break;
      case 'J': t += s == b ? 20 : 2; break;
      case 'T': t += 10; break;
      case '9': t += s == b ? 14 : 0; break;
    }
  }
  cout << t << endl;
}
