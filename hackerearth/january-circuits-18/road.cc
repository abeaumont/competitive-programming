// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/road-1-63e2e618/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int best = 0;

void s(const vi &v, int i, int c, int k) {
  if (k < 0) return;
  if (i == v.size() - 1) {
    best = max(best, c);
    return;
  }
  for (int j = i + 1; j < v.size(); j++) {
    s(v, j, c + 1, k - abs(v[i] - v[j]));
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  s(v, 0, 1, k);
  cout << best << endl;
}
