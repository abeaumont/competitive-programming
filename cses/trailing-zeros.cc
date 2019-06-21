// https://cses.fi/problemset/task/1618
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
	long long n, s = 0, k = 5;
	cin >> n;
  while (k <= n) s += n / k, k *= 5;
  cout << s << "\n";
}
