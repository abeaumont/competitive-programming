// https://open.kattis.com/problems/coast
#include<bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
using vvb=vector<vb>;
int main(){
  int n,m,c=0;
  cin>>n>>m;
  vvb x(n,vb(m));
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      char c;
      cin>>c;
      x[i][j]=(c=='1');
    }
  vvb a(n,vb(m,true));
  vvb b(n,vb(m));
  function<void(int,int)>dfs=[&](int i, int j){
    if(i<0||i>=n)return;
    if(j<0||j>=m)return;
    if(b[i][j])return;
    if(!x[i][j]){
      a[i][j]=false;
      b[i][j]=true;
      dfs(i-1,j);
      dfs(i+1,j);
      dfs(i,j-1);
      dfs(i,j+1);
    }
  };
  for(int j=0;j<m;j++)dfs(0,j);
  for(int j=0;j<m;j++)dfs(n-1,j);
  for(int i=0;i<n;i++)dfs(i,0);
  for(int i=0;i<n;i++)dfs(i,m-1);
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(a[i][j]){
        if(i>0)c+=!a[i-1][j];
        else c++;
        if(j<m-1)c+=!a[i][j+1];
        else c++;
        if(i<n-1)c+=!a[i+1][j];
        else c++;
        if(j>0)c+=!a[i][j-1];
        else c++;
      }
  cout<<c<<endl;
}
