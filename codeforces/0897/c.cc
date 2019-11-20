// https://codeforces.com/contest/897/problem/C
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;

string s = "What are you doing at the end of the world? Are you busy? Will you save us?",
  a = "What are you doing while sending \"",
  b = "\"? Are you busy? Will you send \"",
  c = "\"?";
vi x(1, s.size());

char f(ll n, ll k) {
  while (n >= x.size()) {
    if (k < a.size()) return a[k];
    k -= a.size(), n--;
  }
  while (n) {
    if (k < a.size()) return a[k];
    k -= a.size();
    if (k < x[n-1]) {
      n--;
      continue;
    }
    k -= x[n-1];
    if (k < b.size()) return b[k];
    k -= b.size();
    if (k < x[n - 1]) {
      n--;
      continue;
    }
    k -= x[n-1];
    if (k < c.size()) return c[k];
    return '.';
  }
  if (k < s.size()) return s[k];
  return '.';
}

int main() {
  while(x.back() <= 2e18)
    x.push_back(a.size() + b.size() + c.size() + 2 * x.back());
  ll q, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    cout << f(n, k-1);
  }
  cout << '\n';
}
