// https://www.codechef.com/OCT18A/problems/MINDSUM
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;
typedef tuple<ll,ll,ll> iii;

ll digitsum(ll n) {
  ll s = 0;
  while (n > 0) {
    s += n % 10;
    n /= 10;
  }
  return s;
}
  
const ll INF = 100000000000000LL;

int main() {
  int t; cin >> t;
  while(t--) {
    ll n, d, b, c, e, a[10] = {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF};
    cin >> n >> d;
    queue<iii> q;
    q.push({n, 0, 0});
    while(!q.empty()) {
      tie(b,c,e) = q.front();
      q.pop();
      if (e >= 10) continue;
      q.push({b+d, c+1, e+1});
      if (b < 10) a[b] = min(a[b], c);
      else q.push({digitsum(b), c+1, e});
    }
    for (int i = 0; i < 10; i++)
      if (a[i] < INF) {
        cout << i << " " << a[i] << endl;
        break;
      }
  }
}
