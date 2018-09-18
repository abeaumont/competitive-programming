// https://www.codechef.com/SEPT18A/problems/XORIER
#include <iostream>

using namespace std;

typedef long long ll;

const int M = 1000010;
ll t,n,x,e,o,s,a[M];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    s = 0, e = 0, o = 0;
    for (int i = 0; i < M; i++) a[i] = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a[x]++;
      if (x%2) o++;
      else e++;
    }
    for (int i = 1; i < M-4;i++) s += a[i]*((i%2?o:e)-a[i]-a[i^2]);
    cout << s/2 << endl;
  }
}
