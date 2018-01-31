// https://www.hackerearth.com/challenge/competitive/january-circuits-18/approximate/array-construction-410b758b/
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unordered_set<int> si;

int main() {
  int n, m;
  cin >> n >> m;
  vvi c(n);
  for (int i = 0; i < n; i++) {
    c[i] = vi(n);
    for (int j = 0; j < n; j++) cin >> c[i][j];
  }
  int q = m / n;
  int r = m % n;
  int a = n - r;
  int b = r;
  if (r == 0) {
    for (int i = 0; i < n; i++) {
      cout << q;
      if (i < n - 1) cout << " ";
      else cout << endl;
    }
    return 0;
  }
  si x;
  si y;
  for (int i = 0; i < a; i++) x.insert(i);
  for (int i = 0; i < b; i++) y.insert(a + i);
  vi t(n, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) t[i] += c[i][j];
  for (int Z = 0; Z < 100; Z++) {
    vi d(n);
    for (auto k : x) for (auto l : y) d[k] += c[k][l];
    for (auto k : y) for (auto l : x) d[k] += c[k][l];
    vi g, av, bv;
    si sa, sb;
    for (auto k : x) sa.insert(k);
    for (auto k : y) sb.insert(k);
    while (!sa.empty() && !sb.empty()) {
      int M = 1000000000L;
      int K;
      for (auto k : sa) {
        int D = 2 * d[k] - t[k];
        if (D < M) {
          M = D;
          K = k;
        }
      }
      for (auto k : sa) d[k] += c[k][K];
      for (auto k : sb) d[k] -= c[k][K];
      sa.erase(K);
      av.push_back(K);
      int T = M;
      M = -1;
      for (auto k : sb) {
        int D = 2 * d[k] - t[k];
        if (D < M) {
          M = D;
          K = k;
        }
      }
      for (auto k : sa) d[k] -= c[k][K];
      for (auto k : sb) d[k] += c[k][K];
      sb.erase(K);
      bv.push_back(K);
      T += M;
      g.push_back(T);
    }
    int I = 0;
    int S = 0;
    int M = 0;
    for (int i = 0; i < g.size(); i++) {
      S += g[i];
      if (S > M) {
        M = S;
        I = i;
      }
    }
    if (M == 0) break;
    for (auto k : av) {
      x.erase(k);
      y.insert(k);
    }
    for (auto k : bv) {
      y.erase(k);
      x.insert(k);
    }
  }
  for (int i = 0; i < n; i++) {
    if (x.count(i)) cout << q;
    else cout << q + 1;
    if (i < n - 1) cout << " ";
    else cout << endl;
  }
}
