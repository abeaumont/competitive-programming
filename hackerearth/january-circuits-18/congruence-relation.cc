// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/congruence-relation-ddd2b5cc/
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  int q = n / k;
  int r = n % k;
  ll s1 = ll(q) * (q - 1) / 2;
  ll s2 = ll(q) * (q + 1) / 2;
  cout << s2 * r + s1 * (k - r) << endl;
}
