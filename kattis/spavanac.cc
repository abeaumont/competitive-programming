// https://open.kattis.com/problems/spavanac
#include <iostream>

using namespace std;

int main() {
  int h, m;
  cin >> h >> m;
  int t = (h * 60 + m) - 45;
  if (t < 0) t += 24 * 60;
  cout << (t / 60) << " " << (t % 60) << endl;
}

