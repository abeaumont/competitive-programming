// https://open.kattis.com/problems/pot
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int p = x % 10;
    x = x / 10;
    ll prod = 1;
    for (int j = 0; j < p; j++) {
      prod *= x;
    }
    sum += prod;
  }
  cout << sum << endl;
}
