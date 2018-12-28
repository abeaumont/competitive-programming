// https://open.kattis.com/problems/aprizenoonecanwin
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int n,x;
  cin>>n>>x;
  vi a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  int i=1;
  for(;i<n;i++)if(a[i]+a[i-1]>x)break;
  cout<<i<<endl;
}
