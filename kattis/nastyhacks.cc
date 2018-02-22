// https://open.kattis.com/problems/nastyhacks
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r, e, c;
    cin >> r >> e >> c;
    if (r + c == e) cout << "does not matter\n";
    else if (r + c < e) cout << "advertise\n";
    else cout << "do not advertise\n";
  }
}
