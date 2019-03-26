// https://uva.onlinejudge.org/external/2/260.pdf
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
using vb=vector<bool>;
using vvb=vector<vb>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int t=1;;t++){
    int n;
    cin>>n;
    if(!n)break;
    vs a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvb s(n,vb(n));
    function<void(int,int)>dfs=[&](int y,int x){
      s[y][x]=1;
      if(y>0&&x>0&&!s[y-1][x-1]&&a[y-1][x-1]=='w')dfs(y-1,x-1);
      if(y>0&&!s[y-1][x]&&a[y-1][x]=='w')dfs(y-1,x);
      if(x>0&&!s[y][x-1]&&a[y][x-1]=='w')dfs(y,x-1);
      if(x<n-1&&!s[y][x+1]&&a[y][x+1]=='w')dfs(y,x+1);
      if(y<n-1&&!s[y+1][x]&&a[y+1][x]=='w')dfs(y+1,x);
      if(y<n-1&&x<n-1&&!s[y+1][x+1]&&a[y+1][x+1]=='w')dfs(y+1,x+1);
    };
    for(int i=0;i<n;i++)
      if(!s[i][0]&&a[i][0]=='w')
        dfs(i,0);
    bool f=0;
    for(int i=0;i<n;i++)
      if(s[i][n-1])
        f=1;
    cout<<t<<" "<<"BW"[f]<<"\n";
  }
}
