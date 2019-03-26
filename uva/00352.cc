// https://uva.onlinejudge.org/external/3/352.pdf
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
using vb=vector<bool>;
using vvb=vector<vb>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  for(int t=1;cin>>n;t++){
    vs a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvb s(n,vb(n));
    function<void(int,int)>dfs=[&](int y,int x){
      s[y][x]=1;
      if(x>0&&!s[y][x-1]&&a[y][x-1]=='1')dfs(y,x-1);
      if(y>0&&x>0&&!s[y-1][x-1]&&a[y-1][x-1]=='1')dfs(y-1,x-1);
      if(y>0&&!s[y-1][x]&&a[y-1][x]=='1')dfs(y-1,x);
      if(y>0&&x<n-1&&!s[y-1][x+1]&&a[y-1][x+1]=='1')dfs(y-1,x+1);
      if(x<n-1&&!s[y][x+1]&&a[y][x+1]=='1')dfs(y,x+1);
      if(y<n-1&&x<n-1&&!s[y+1][x+1]&&a[y+1][x+1]=='1')dfs(y+1,x+1);
      if(y<n-1&&!s[y+1][x]&&a[y+1][x]=='1')dfs(y+1,x);
      if(y<n-1&&x>0&&!s[y+1][x-1]&&a[y+1][x-1]=='1')dfs(y+1,x-1);
    };
    int k=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(!s[i][j]&&a[i][j]=='1'){
          k++;
          dfs(i,j);
        }
    cout<<"Image number "<<t<<" contains "<<k<<" war eagles.\n";
  }
}
