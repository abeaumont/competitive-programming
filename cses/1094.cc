// https://cses.fi/problemset/task/1094/
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll sum = 0;
  int a, b;
  cin >> a;
  for (int i = 1; i < n; i++) {
    cin >> b;
    if (b < a) sum += a - b;
    else a = b;
  }
  cout << sum << endl;
}
