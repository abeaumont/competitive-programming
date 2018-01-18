// https://open.kattis.com/problems/dst
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    char c;
    int d, h, m;
    cin >> c >> d >> h >> m;
    int t = h * 60 + m;
    if (c == 'F') t += d;
    else t -= d;
    if (t < 0) t += 24 * 60;
    else if (t >= 24 * 60) t -= 24 * 60;
    cout << t / 60 << " " << t % 60 << endl;
  }
}
