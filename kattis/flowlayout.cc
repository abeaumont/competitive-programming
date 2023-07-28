// https://open.kattis.com/problems/flowlayout
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int m, w, h;
  while (1) {
    cin >> m;
    if (!m) break;
    int mw = 0, mh = 0, cw = 0, ch = 0;
    while (1) {
      cin >> w >> h;
      if (w < 0 && h < 0) break;
      if (cw + w > m) {
        mw = max(mw, cw);
        cw = w;
        ch += mh;
        mh = h;
      } else {
        cw += w;
        mh = max(mh, h);
      }
    }
    cout << max(mw, cw) << " x " << ch + mh << '\n';
  }
}
