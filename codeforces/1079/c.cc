// https://codeforces.com/contest/1079/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  int n;
  cin>>n;
  vi a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  vvi dp(n, vi(6));
  for(int i=1;i<n;i++)
    for(int j=1;j<6;j++){
      dp[i][j]=-1;
      if(a[i]==a[i-1]){
        for(int k=1;k<6;k++)
          if(j!=k&&dp[i-1][k]!=-1)dp[i][j]=k;
      }else if(a[i]>a[i-1]){
        for(int k=1;k<j;k++)
          if(dp[i-1][k]!=-1)dp[i][j]=k;
      }else{
        for(int k=j+1;k<6;k++)
          if(dp[i-1][k]!=-1)dp[i][j]=k;
      }
    }
  for(int i=1;i<6;i++)
    if(dp[n-1][i]!=-1){
      vi r(n);
      for(int j=0;j<n;j++){
        r[n-1-j]=i;
        i=dp[n-j-1][i];
      }
      for(int j=0;j<n;j++)cout<<r[j]<<" \n"[j==n-1];
      return 0;
    }
  cout<<"-1\n";
}
