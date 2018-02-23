// https://open.kattis.com/problems/speedlimit
#include <iostream>

using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == -1) break;
    int sum = 0;
    int p = 0;
    for (int i = 0; i < n; i++) {
      int s, t;
      cin >> s >> t;
      sum += s * (t - p);
      p = t;
    }
    cout << sum << " miles" << endl;
  }
}
