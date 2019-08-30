// https://cses.fi/problemset/task/1190/
#include <iostream>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<ll,ll,ll,ll> iiii;

const int N = 500000;
iiii t[4*N];
int nn,n,m,k;
ll x,a,a1,a2,b,b1,b2,c,c1,c2,m1,m2, mm;

void update(int i, ll x) {
  i += nn;
  t[i] = {x, x, x, x};
  while (i >= 2) {
    i /= 2;
    tie(a1,b1,c1,m1) = t[i*2];
    tie(a2,b2,c2,m2) = t[i*2+1];
    b = b1+b2;
    a = max(a1,max(b1+a2,b));
    c = max(c2,max(c1+b2,b));
    mm = max(m1,m2);
    mm = max(mm, a); mm = max(mm, b); mm = max(mm, c);
    mm = max(mm, c1+a2);
    t[i] = {a,b,c,mm};
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (nn = 1; nn < n; nn*=2);
  for (int i = 0; i < n; i++) {
    cin >> x;
    update(i, x);
  }
  for (int i = 0; i < m; i++) {
    cin >> k >> x;
    update(k-1, x);
    tie(a,b,c,m1) = t[1];
    cout << m1 << "\n";
  }
}
