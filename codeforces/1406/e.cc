// https://codeforces.com/contest/1406/problem/E
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<bool> primesieve(n + 1, true);
  primesieve[0] = false;
  primesieve[1] = false;
  for (int i = 2; i <= n; i++)
    if (primesieve[i])
      for (int j = i * 2; j <= n; j += i) primesieve[j] = false;
  vector<ll> primes;
  for (int i = 2; i <= n; i++)
    if (primesieve[i]) primes.push_back(i);
  int r = 1, x;
  int i = 0;
  while (i < primes.size()) {
    ll p = primes[i];
    if (p * p > n) break;
    i++;
    ll q = p;
    while (q <= n) {
      cout << "B " << q << endl;
      cin >> x;
      if (p == q) {
        cout << "A " << q << endl;
        cin >> x;
      }
      if (!x) {
        q /= p;
        break;
      }
      q *= p;
    }
    if (q > n) q /= p;
    r *= q;
  }
  cout << "A 1" << endl;
  int count;
  cin >> count;
  vector<ll> pending;
  while (i < primes.size()) {
    ll p = primes[i];
    cout << "B " << p << endl;
    cin >> x;
    if (x > 1) r *= p;
    pending.push_back(p);
    i++;
    count--;
    if (pending.size() >= 100) {
      cout << "A 1" << endl;
      cin >> x;
      if (x != count) {
        for (int q : pending) {
          cout << "A " << q << endl;
          cin >> x;
          if (x) {
            r *= q;
            break;
          }
        }
        pending.clear();
        break;
      }
      pending.clear();
    }
  }
  if (pending.size()) {
    cout << "A 1" << endl;
    cin >> x;
    if (x != count)
      for (int q : pending) {
        cout << "A " << q << endl;
        cin >> x;
        if (x) {
          r *= q;
          break;
        }
      }
  }
  cout << "C " << r << endl;
}
