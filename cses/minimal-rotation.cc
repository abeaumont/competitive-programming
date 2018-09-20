// https://cses.fi/problemset/task/1110
#include <iostream>

using namespace std;

typedef long long ll;

const ll A=911382323,B=972663749,N=1000000;
ll h[2*N],p[2*N];

int main() {
  string s;
  cin >> s;
  int n = s.size();
  s += s;
  h[0] = s[0];
  p[0] = 1;
  for (int i = 1; i < 2*n; i++) {
    h[i] = (h[i-1]*A+s[i])%B;
    p[i] = (p[i-1]*A)%B;
  }
  int j=0;
  for (int i = 1; i < n; i++) {
    if (s[j]<s[i]) continue;
    if (s[j]>s[i]) {
      j=i;
      continue;
    }
    int k = 0;
    for (int b=n/2; b >= 1; b /= 2)
      while (k+b < n) {
        ll x = (h[i+k+b]-h[i-1]*p[k+b+1])%B;
        ll y = (h[j+k+b]-(j?h[j-1]*p[k+b+1]:0))%B;
        if (x<0) x+=B;
        if (y<0) y+=B;
        if (x == y) k += b;
        else break;
      }
    if (k == n-1) continue;
    if (s[j+k+1]>s[i+k+1])j=i;
  }
  cout << s.substr(j, n) << endl;
}
