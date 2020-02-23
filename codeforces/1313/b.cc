// https://codeforces.com/contest/1313/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    int score = x+y;
    int worst, best;
    if (score > n+1) worst = n;
    else worst = score-1;
    if (score <= n) best = 1;
    else best = min(n, score-n+1);
    cout << best << " " << worst << endl;
  }
}
