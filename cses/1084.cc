// https://cses.fi/problemset/task/1084/
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vi a(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  vi b(m);
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int i = 0;
  int j = 0;
  int c = 0;
  while (i < n && j < m)
    if (a[i] + k < b[j]) i++;
    else if (a[i] - k > b[j]) j++;
    else { i++; j++; c++; }
  cout << c << endl;
}
