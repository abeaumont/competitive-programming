// https://code.google.com/codejam/contest/5314486/dashboard#s=p1
#include <bits/stdc++.h>

using namespace std;
using vi=vector<int>;

int main(){
  int T,n,c,m,p,b;
  cin>>T;
  for(int t=1;t<=T;t++){
    cin>>n>>c>>m;
    vi a(n),d(c);
    for(int i=0;i<m;i++){
      cin>>p>>b;
      p--;b--;
      a[p]++;
      d[b]++;
    }
    int M=0;
    for(int i=0;i<c;i++)M=max(M,d[i]);
    int s=0;
    for(int i=0;i<n;i++){
      s+=a[i];
      M=max((s-1)/(i+1)+1,M);
    }
    int k=0;
    for(int i=0;i<n;i++)
      if(a[i]>M)k+=a[i]-M;
    printf("Case #%d: %d %d\n",t,M,k);
  }
}
