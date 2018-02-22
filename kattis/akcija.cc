// https://open.kattis.com/problems/akcija
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.rbegin(), v.rend());
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 3 == 2) continue;
    sum += v[i];
  }
  cout << sum << endl;
}
