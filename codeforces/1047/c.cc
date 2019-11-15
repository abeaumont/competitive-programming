// https://codeforces.com/contest/1047/problem/C
#include <bits/stdc++.h>

using namespace std;

const int N = 15000000;
bool primes[N];
int p, ps[N],a[N], factors[N];

void f() {
  for (int i = 2; i < N; i++) primes[i] = true;
  for (int i = 2; i < N; i++)
    if (primes[i])
      for (int j = 2*i; j < N; j+=i)
        primes[j]=false;
  for (int i = 0; i < N; i++)
    if (primes[i]) ps[p++] = i;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  f();
  int n, x, g;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!i) g = a[i];
    else g = __gcd(g, a[i]);
  }
  for (int i = 0; i < n; i++) {
    x = a[i]/g;
    int j = 0;
    while (x > 1) {
      if (primes[x]) {
        factors[x]++;
        break;
      }
      if (!(x%ps[j])) {
        factors[ps[j]]++;
        while(!(x%ps[j])) x/=ps[j];
      }
      j++;
    }
  }
  int m = 0;
  for (int i = 0; i < N; i++)
    if (factors[i] < n) m = max(factors[i], m);
  if (m) cout << (n - m) << endl;
  else cout << "-1\n";
}
