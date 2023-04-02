// https://open.kattis.com/problems/martiandna
#include <bits/stdc++.h>

using namespace std;
const int N = 200000;
bool req[N];
int s[N], c[N], d[N];

int main() {
  int n, k, r;
  cin >> n >> k >> r;
  for (int i = 0; i < n; i++) cin >> s[i];
  set<int> xs;
  for (int i = 0; i < r; i++) {
    int p;
    cin >> p;
    cin >> c[p];
    xs.insert(p);
    req[p] = 1;
  }
  int start = 0;
  int best = n + 1;
  for (int i = 0; i < n; i++) {
    int x = s[i];
    if (req[x]) {
      d[x]++;
      if (c[x] == d[x]) {
        xs.erase(x);
        if (xs.empty()) {
          best = min(best, i - start + 1);
          while (true) {
            x = s[start];
            if (!req[x]) {
              start++;
              best = min(best, i - start + 1);
              continue;
            }
            if (c[x] == d[x]) {
              xs.insert(x);
              d[x]--;
              start++;
              break;
            } else {
              start++;
              best = min(best, i - start + 1);
              d[x]--;
            }
          }
        }
      }
    }
  }
  if (best == n + 1) cout << "impossible\n";
  else
    cout << best << '\n';
}
