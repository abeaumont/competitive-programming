// https://www.codechef.com/FEB18/problems/CHEFPTNT
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, x, k;
    cin >> n >> m >> x >> k;
    string s;
    cin >> s;
    int e = count(s.begin(), s.end(), 'E');
    int o = s.size() - e;
    int sum = min(m / 2 * x, e) + min((m + 1) / 2 * x, o);
    cout << (sum >= n ? "yes\n" : "no\n");
  }
}
