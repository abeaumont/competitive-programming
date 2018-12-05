// https://codeforces.com/contest/4/problem/D
#include <bits/stdc++.h>
using namespace std;
using iii=tuple<int,int,int>;
using vi=vector<int>;
using viii=vector<iii>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,w,h,x,y;
  cin>>n>>w>>h;
  viii a;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    if(x<=w||y<=h)continue;
    a.push_back({x,y,i});
  }
  sort(a.rbegin(),a.rend());
  a.push_back({w,h,-1});
  n=a.size();
  vi dp(n),p(n);
  for(int i=n-2;i>=0;i--)
    for(int j=n-1;j>i;j--){
      int wi,hi,ii,wj,hj,ij;
      tie(wi,hi,ii)=a[i];
      tie(wj,hj,ij)=a[j];
      if(wj<wi&&hj<hi&&dp[j]>=dp[i]){
        dp[i]=dp[j]+1;
        p[i]=j;
      }
    }
  int m=0,k;
  for(int i=0;i<n;i++)
    if(dp[i]>m){
      k=i;
      m=dp[i];
    }
  cout<<m<<endl;
  if(!m)return 0;
  vi b(m);
  for(int i=0;i<m;i++){
    int l=get<2>(a[k]);
    b[m-i-1]=l;
    k=p[k];
  }
  for(int i=0;i<m;i++)cout<<b[i]+1<<" \n"[i==m-1];
  
}
