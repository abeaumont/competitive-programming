// https://uva.onlinejudge.org/external/103/10382.pdf
#include <cmath>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<double, double> dd;
typedef vector<dd> vdd;

int main() {
  while (true) {
    int n, l, w;
    cin >> n >> l >> w;
    if (cin.peek() == EOF) break;
    vdd v;
    for (int i = 0; i < n; i++) {
      int x, r;
      cin >> x >> r;
      if (r * 2 <= w) continue;
      double theta = asin(double(w) / 2.0 / double(r));
      double a = x - r * cos(theta);
      double b = x + r * cos(theta);
      v.push_back(dd(a, b));
    }
    sort(v.begin(), v.end(), [](dd x, dd y) { return get<0>(x) < get<0>(y); });
    for (auto x : v) {
      double a, b;
      tie(a, b) = x;
    }
    int i = 0;
    double pos = 0.0;
    double endpos = 0.0;
    int count = 0;
    while (true) {
      if (i >= v.size()) {
        if (endpos >= l) count++;
        else count = -1;
        break;
      }
      double a, b;
      tie(a, b) = v[i];
      if (a <= pos) {
        if (b > endpos) {
          endpos = b;
        }
        i++;
        continue;
      }
      if (endpos == 0.0) {
        count = -1;
        break;
      }
      count++;
      if (endpos >= l) break;
      pos = endpos;
      endpos = 0.0;
    }
    cout << count << endl;
  }
}
