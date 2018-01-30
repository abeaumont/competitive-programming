// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/theatre-830bdbff/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n, k;
  cin >> n >> k;
  vvi v(n);
  for (int i = 0; i < n; i++) {
    v[i] = vi(3);
    for (int j = 0; j < 3; j++) cin >> v[i][j];
  }
  int m = k * 3;
  for (int i = 0; i < k; i++) {
    int M = 0;
    for (int j = 0; j < n; j++) {
      M = max(M, (v[j][0] + i) % k + (v[j][1] + i) % k + (v[j][2] + i) % k);
    }
    m = min(M, m);
  }
  cout << m << endl;
}
