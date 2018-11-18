// https://codeforces.com/problemsets/acmsguru/problem/99999/116
#include <bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
using vi=vector<int>;
int INF=1000000000;
int main(){
  int n;
  cin >>n;
  vb p(n+1,true);
  p[0]=p[1]=false;
  for(int i=2;i<=n;i++)
    if(p[i])
      for(int j=i*2;j<=n;j+=i)
        p[j]=false;
  vi s;
  for(int i=0,j=1;i<=n;i++)
    if (p[i]&&p[j++])s.push_back(i);
  vi w,v;
  for(int x:s)
    for(int i=1;i*x<=n;i++) {
      w.push_back(i*x);
      v.push_back(i);
    }
  vi dp(n+1,INF);
  vi f(n+1);
  dp[0]=0;
  for(int i=1;i<=n;i++)
    for(int j=0;j<w.size();j++)
      if(w[j]<=i&&dp[i-w[j]]+v[j]<dp[i]){
        dp[i]=dp[i-w[j]]+v[j];
        f[i]=j;
      }
  if (dp[n]==INF){
    cout<<"0\n\n";
    return 0;
  }
  vi r;
  while(n>0){
    int j=f[n];
    for(int i=0;i<v[j];i++) r.push_back(w[j]/v[j]);
    n-=w[j];
  }
  assert(!n);
  sort(r.begin(),r.end(),greater<int>());
  n=r.size();
  assert(r.size()==dp.back());
  cout<<n<<endl;
  for(int i=0;i<n;i++)cout<<r[i]<<" \n"[i==n-1];
}
