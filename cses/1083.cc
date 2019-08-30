// https://cses.fi/problemset/task/1083/
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int n, x;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n - 1; i++) {
    cin >> x;
    sum += x;
  }
  cout << ll(n) * (n + 1) / 2 - sum << endl;
}
