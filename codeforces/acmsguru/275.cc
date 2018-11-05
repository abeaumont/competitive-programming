// https://codeforces.com/problemsets/acmsguru/problem/99999/275
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
int main(){
  int n;
  cin>>n;
  vi a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  for(ll i=1LL<<60,j=0;i>0;i/=2) {
    int k=j;
    while(k<n&&!(a[k]&i))k++;
    if(k==n)continue;
    if(k>j)swap(a[j],a[k]);
    for (int k=0;k<n;k++)
      if(a[k]&i&&j!=k)a[k]^=a[j];
    j++;
  }
  ll m=0;
  for(int i=0;i<n;i++)m^=a[i];
  cout<<m<<endl;
}
