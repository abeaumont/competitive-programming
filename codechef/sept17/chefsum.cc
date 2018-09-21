// https://www.codechef.com/SEPT17/problems/CHEFSUM/
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vi v = vi(n);
    vll prefix = vll(n, 0);
    for (int j = 0; j < n; j++) {
      cin >> v[j];
      prefix[j] += v[j];
      if (j > 0) {
        prefix[j] += prefix[j-1];
      }
    }
    vll suffix = vll(n);
    suffix[n - 1] = v[n - 1];
    for (int j = n - 2; j >= 0; j--) {
      suffix[j] += suffix[j + 1] + v[j];
    }
    int m = 0;
    ll sum = 100000000000;
    for (int j = 0; j < n; j++) {
      ll x = prefix[j] + suffix[j];
      if (x < sum) {
        m = j;
        sum = x;
      }
    }
    cout << m + 1 << endl;
  }
}
