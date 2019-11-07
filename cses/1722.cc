// https://cses.fi/problemset/task/1722
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

ll M = 1000000007;

vi fib(ll n) {
  if (n == 1) return {0, 1, 1, 1,};
  vi x = fib(n / 2);
  x = {((x[0] * x[0]) % M + (x[1] * x[2]) % M) % M,
       ((x[0] * x[1]) % M + (x[1] * x[3]) % M) % M,
       ((x[2] * x[0]) % M + (x[3] * x[2]) % M) % M,
       ((x[2] * x[1]) % M + (x[3] * x[3]) % M) % M};
  if (n % 2)
    x = {x[1], (x[0] + x[1]) % M, x[3], (x[2] + x[3]) % M};
  return x;
}

int main() {
  ll n;
  cin >> n;
  cout << fib(n + 1)[0] << "\n";
}
