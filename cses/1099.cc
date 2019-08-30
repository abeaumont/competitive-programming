// https://cses.fi/problemset/task/1099/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 2; i > 0; i--) a[i] += a[i+1];
    for (int i = 1; i < n; i++) s ^= a[i];
    cout << (s ? "first\n" : "second\n");
  }
}
