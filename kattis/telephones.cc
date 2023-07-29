// https://open.kattis.com/problems/telephones
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;
pair<int, int> calls[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int n, m;
    cin >> n >> m;
    if (!n) break;
    for (int i = 0; i < n; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      calls[i] = {c, c + d};
    }
    while (m--) {
      int start, end;
      cin >> start >> end;
      end += start;
      int c = 0;
      for (int i = 0; i < n; i++) {
        int s, e;
        tie(s, e) = calls[i];
        c += s < end && e > start;
      }
      cout << c << '\n';
    }
  }
}
