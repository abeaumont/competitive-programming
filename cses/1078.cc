// https://cses.fi/problemset/task/1078/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<ll,ll> ii;

ll M=1000000007;
const ll N=2000000;
ll f[N],inv[N],invf[N];

ll modinv(ll a, ll b) {
  ll b0 = b, t, q;
  ll x0 = 0, x1 = 1;
  if (b == 1) return 1;
  while (a > 1) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  return x1;
}

ll binomial(ll n, ll k, ll m) {
  ll c=1;
  while(n||k) {
    ll a=n%m,b=k%m;
    if(a<b) return 0;
    c=c*f[a]%m*invf[b]%m*invf[a-b]%m;
    n/=m;k/=m;
  }
  return c;
}


int main() {
  f[1]=1;
  for (int i=2;i<N;i++) f[i]=f[i-1]*i%M;
  inv[1]=1;
  for (int i=2;i<N;i++) inv[i]=M-(M/i)*inv[M%i]%M;
  invf[0]=1;
  for (int i=1;i<N;i++) invf[i]=invf[i-1]*inv[i]%M;
  
  ll n,m,y,x;
  cin>>n>>m;
  ii z[m];
  ll c[m];
  for (int i=0;i<m;i++) {
    cin>>y>>x;
    z[i]={y,x};
  }
  sort(z,z+m, [](ii a, ii b) -> bool {
    ll xa,ya,xb,yb;
    tie(ya,xa)=a;
    tie(yb,xb)=b;
    if (ya<=yb&&xa<=xb) return true;
    if (ya>=yb&&xa>=xb) return false;
    return ya<=yb;
  });
  ll r=binomial((n-1)*2,n-1,M);
  for (int i=0;i<m;i++) {
    tie(y,x)=z[i];
    ll a=max(x,y), b=min(x,y);
    c[i]=binomial(a+b-2,b-1,M);
    for (int j=0;j<i;j++) {
      ll py,px;
      tie(py,px)=z[j];
      if (py>y||px>x) continue;
      ll pa=max(y-py,x-px),pb=min(y-py,x-px);
      c[i]=(c[i]-c[j]*binomial(pa+pb,pb,M)%M)%M;
    }
    ll d=n-b,e=n-a;
    r=(r-c[i]*binomial(d+e,e,M)%M)%M;
    if (r<0) r+=M;
  }
  cout<<r<<endl;
}
