// https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
int d[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int T, n;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n);
    int c = 0, k = 0;
    for (int i = 0; i < n; i++) {
      if (k < d[i]) c++, k++;
    }
    cout << "Case #" << t << ": " << c << '\n';
  }
}
