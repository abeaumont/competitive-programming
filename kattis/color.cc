// https://open.kattis.com/problems/color
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
  int s, c, k;
  cin >> s >> c >> k;
  vi v(s);
  for (int i = 0; i < s; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int t = 1;
  int l = v[0];
  int m = 1;
  for (int i = 1; i < s; i++) {
    if (m >= c || v[i] - l > k) {
      t++;
      l = v[i];
      m = 1;
    } else m++;
  }
  cout << t << endl;
}
