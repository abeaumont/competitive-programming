// https://codeforces.com/contest/1068/problem/B
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unordered_map<ll, ll> mii;

int main() {
  ll b;
  cin >> b;
  mii m;
  ll i = 2;
  while (i*i <= b) {
    while (!(b%i)) {
      b/=i;
      m[i]++;
    }
    i++;
  }
  if (b > 1) m[b]++;
  ll s = 1;
  for (auto z:m) s *= (z.second+1);
  cout << s << endl;
}
