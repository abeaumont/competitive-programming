// https://uva.onlinejudge.org/external/6/657.pdf
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int t=1;;t++){
    int n,m;
    cin>>m>>n;
    if(!n)break;
    vs a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvi s(n,vi(m));
    function<void(int,int,int)>dfs=[&](int i,int j,int k){
      s[i][j]=k;
      int y[]={-1,0,0,1};
      int x[]={0,-1,1,0};
      for(int l=0;l<4;l++){
        int u=i+y[l],v=j+x[l];
        if(u>=0&&u<n&&v>=0&&v<m&&!s[u][v]&&(a[u][v]=='*'||a[u][v]=='X'))
          dfs(u,v,k);
      }
    };
    int k=1;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(!s[i][j]&&(a[i][j]=='*'||a[i][j]=='X'))
          dfs(i,j,k++);
    vvi r(n,vi(m));
    function<void(int,int,int)>dfs2=[&](int i,int j,int k){
      r[i][j]=k;
      int y[]={-1,0,0,1};
      int x[]={0,-1,1,0};
      for(int l=0;l<4;l++){
        int u=i+y[l],v=j+x[l];
        if(u>=0&&u<n&&v>=0&&v<m&&!r[u][v]&&a[u][v]=='X')
          dfs2(u,v,k);
      }
    };
    int l=1;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(!r[i][j]&&a[i][j]=='X')
          dfs2(i,j,l++);
    vi b(k),c(l);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(r[i][j]&&!c[r[i][j]]){
          c[r[i][j]]=1;
          b[s[i][j]]++;
        }
    sort(b.begin(),b.end());
    cout<<"Throw "<<t<<"\n";
    for(int i=1;i<k;i++)cout<<b[i]<<" \n"[i==k-1];
    cout<<"\n";
  }
}
