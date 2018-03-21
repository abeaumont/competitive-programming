// https://www.codechef.com/JAN18/problems/MONSTER
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
  int n, q, x, y;
  cin >> n;
  vi h(n + 1);
  for (int i = 0; i < n; i++) cin >> h[i];
  cin >> q;
  int c = n;
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    for (int j = 0; j < n; j++) {
      if ((j & x) == j && h[j] > 0) {
        h[j] -= y;
        if (h[j] <= 0) c--;
      }
    }
    cout << c << endl;
  }
}
