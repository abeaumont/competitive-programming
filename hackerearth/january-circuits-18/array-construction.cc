// https://www.hackerearth.com/challenge/competitive/january-circuits-18/approximate/array-construction-410b758b/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n, m;
  cin >> n >> m;
  vvi v(n);
  for (int i = 0; i < n; i++) {
    v[i] = vi(n);
    for (int j = 0; j < n; j++) cin >> v[i][j];
  }
  for (int i = 0; i < n - 1; i++) cout << 0 << " ";
  cout << m << endl;
}
