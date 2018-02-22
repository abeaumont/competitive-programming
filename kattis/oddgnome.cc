// https://open.kattis.com/problems/oddgnome
#include <iostream>

using namespace std;

int s() {
  int g, p;
  cin >> g >> p;
  int king = 0;
  for (int j = 1; j < g; j++) {
    int x;
    cin >> x;
    if (!king && x != ++p) king = j + 1;
  }
  return king;
}


int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cout << s() << endl;
}
