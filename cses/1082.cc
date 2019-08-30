// https://cses.fi/problemset/task/1082/
#include <iostream>

using namespace std;

typedef long long ll;

ll M = 1000000007;

int main() {
  ll n;
  cin >> n;
  ll e, b, d=2, s=0;
  do {
    e = n/(d-1);
    b = n/d+1;
    ll x = e-b+1;
    ll y = b+e;
    if (x % 2) y/=2;
    else x/=2;
    x %= M;
    y %= M;
    x = x*y%M;
    x = x*(d-1)%M;
    s = (s+x)%M;
    d++;
  } while(b>d);
  for (int i=1; i<b; i++) s = (s+n/i*i)%M;
  if (s<0) s+=M;
  cout << s << endl;
}
