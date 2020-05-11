// https://www.codechef.com/SNCK1A19/problems/ARRGRAPH
#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N=50, P=15;
int t,n,primes[P] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vvi g(n);
    vb s(P), b(n);
    int a[n],c=0;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      for (int j=0;j<P;j++)
        if (!(a[i]%primes[j]))
          s[j]=1;
    }
    for (int i=0;i<n;i++)
      for (int j=i+1;j<n;j++)
        if (__gcd(a[i],a[j])==1) {
          g[i].push_back(j); g[j].push_back(i);
        }
    function<void(int)> dfs = [&](int u) {
      b[u]=1;
      for (int v:g[u]) {
        if (b[v]) continue;
        dfs(v);
      }
    };
    dfs(0);
    int i = 0;
    while (i < n) {
      if (!b[i]) break;
      i++;
    }
    if (i < n) {
      i = 0;
      while (i < P) {
        if (!s[i]) break;
        i++;
      }
      a[0] = primes[i];
      c++;
    }
    cout << c << endl;
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i==n-1];
  }
}
