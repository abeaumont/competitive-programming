// https://cses.fi/problemset/task/1191
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
int main(){
  ll n,k;
  cin>>n>>k;
  vi a(2*n+2),b(2*n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    a[i+n]=a[i];
    if(i)a[i]+=a[i-1];
  }
  for(int i=n;i<=2*n;i++)a[i+1]+=a[i];
  for(int i=2*n;i>0;i--){
    auto it=upper_bound(&a[i],&a[2*n+1],a[i-1]+k);
    b[i-1]=b[it-&a[1]]+1;
  }
  ll m=n;
  for(int i=1;i<=n;i++){
    if(a[i-1]>k)break;
    m=min(m,b[i]-b[i+n-1]+1);
  }
  cout<<m<<"\n";
}
