// https://uva.onlinejudge.org/external/107/10720.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int n;
  while(1){
    cin>>n;
    if(!n)break;
    vi a(n);
    int o=1;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(&a[0],&a[n],greater<int>());
    if(accumulate(&a[0],&a[n],0)%2)o=0;
    for(int k=1;k<=n;k++){
      int s=0;
      for(int i=k;i<n;i++)s+=min(a[i],k);
      if(accumulate(&a[0],&a[k],0)>k*(k-1)+s)o=0;
    }
    cout<<(o?"Possible\n":"Not possible\n");
  }
}
