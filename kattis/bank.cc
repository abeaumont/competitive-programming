// https://open.kattis.com/problems/bank
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef multiset<int, greater<int>> si;
typedef vector<si> vsi;

int main() {
  int n, t;
  cin >> n >> t;
  vsi v(t);
  for (int i = 0; i < n; i++) {
    int ci, ti;
    cin >> ci >> ti;
    v[ti].insert(ci);
  }
  ll sum = 0;
  for (int i = t - 1; i >= 0; i--) {
    int m = 0;
    int k = -1;
    for (int j = i; j < t; j++) {
      auto it = v[j].begin();
      if (it == v[j].end()) continue;
      if (*it > m) {
        k = j;
        m = *it;
      }
    }
    if (k >= 0) {
      sum += m;
      v[k].erase(v[k].begin());
    }
  }
  cout << sum << endl;
}
