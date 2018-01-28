// https://open.kattis.com/problems/pivot
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vi l(n, v[0]);
  for (int i = 1; i < n; i++) l[i] = max(v[i], l[i-1]);
  vi r(n, v[n - 1]);
  for (int i = n - 2; i >= 0; i--) r[i] = min(v[i], r[i+1]);
  int s = 0;
  for (int i = 0; i < n; i++) s += v[i] == l[i] && v[i] == r[i];
  cout << s << endl;
}
