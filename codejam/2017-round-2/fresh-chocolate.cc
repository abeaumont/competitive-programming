// https://code.google.com/codejam/contest/5314486/dashboard#s=p0
#include <bits/stdc++.h>

using namespace std;
using vi=vector<int>;

int main() {
  int T,n,p,x;
  cin>>T;
  for(int t=1;t<=T;t++){
    cin>>n>>p;
    vi a(p);
    for (int i=0;i<n;i++){
      cin>>x;
      a[x%p]++;
    }
    int c=a[0];
    if(p==2){
      c+=a[1]/2;
      a[1]-=(a[1]/2)*2;
    } else if(p==3){
      int k=min(a[1],a[2]);
      c+=k;
      a[1]-=k;
      a[2]-=k;
      k=max(a[1],a[2]);
      if(a[1])a[1]-=(k/3);
      if(a[2])a[2]-=(k/3);
      c+=(k-1)/3;
    } else{
      c+=a[2]/2;
      a[2]=a[2]%2;
      int k=min(a[1],a[3]);
      c+=k;
      a[1]-=k;
      a[3]-=k;
      if (a[2]&&max(a[1],a[3])>=2) {
        c++;
        a[2]=0;
        if(a[1])a[1]-=2;
        else a[3]-=2;
      }
      k=max(a[1],a[3]);
      c+=k/4;
      if(a[1])a[1]-=(k/4)*4;
      else a[3]-=(k/4)*4;
    }
    int s=0;
    for(int i=1;i<p;i++) s+=a[i];
    if(s)c++;
    printf("Case #%d: %d\n",t,c);
  }
}
