// https://cses.fi/problemset/task/1159/
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ii z[1000];
int h[100], s[100], k[100], a[1001][100001];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) cin >> k[i];
  int l = 0;
  for (int i = 0; i < n; i++) {
    int t = 0;
    for (int j = 1; t + j < k[i]; j *= 2) {
      if (h[i]*j > x) break;
      t += j;
      z[l++] = {h[i]*j, s[i]*j};
    }
    if (t >= k[i]) continue;
    t = k[i] - t;
    if (t*h[i] <= x) z[l++] = {h[i]*t, s[i]*t};
  }
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= l; j++) {
      a[j][i] = a[j-1][i];
      int w, v;
      tie(w, v) = z[j-1];
      if (w <= i) a[j][i] = max(a[j][i], a[j-1][i-w]+v);
    }
  cout << a[l][x] << endl;
}
