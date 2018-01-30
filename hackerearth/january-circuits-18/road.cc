// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/road-1-63e2e618/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi cache;

int s(const vi &v, int i, int k) {
  if (cache[i][k] != -1) return cache[i][k];
  int c = 0;
  vb u(k + 1, false);
  for (int j = i + 1; j < v.size(); j++) {
    int k2 = k - abs(v[i] - v[j]);
    if (k2 < 0) continue;
    if (!u[k2]) {
      u[k2] = true;
      c = max(c, 1 + s(v, j, k2));
    }
  }
  cache[i][k] = c;
  return c;
}

int main() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  cache = vvi(n);
  for (int i = 0; i < n; i++) cache[i] = vi(k + 1, -1);
  for (int i = 0; i < n; i++) cin >> v[i];
  cout << 1 + s(v, 0, k) << endl;
}
