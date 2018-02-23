// https://open.kattis.com/problems/minimumscalar
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vll a(n), b(n);
    for (int j = 0; j < n; j++) cin >> a[j];
    for (int j = 0; j < n; j++) cin >> b[j];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    ll p = 0;
    for (int j = 0; j < n; j++) p += a[j] * b[j];
    cout << "Case #" << (i + 1) << ": " << p << endl;
  }
}
