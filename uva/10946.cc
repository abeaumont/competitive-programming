// https://uva.onlinejudge.org/external/109/10946.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
using vb=vector<bool>;
using vvb=vector<vb>;
using vs=vector<string>;
int main(){
  for(int T=1;;T++){
    int n,m;
    cin>>n>>m;
    if(!n)break;
    vs a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvb s(n,vb(m));
    function<int(int,int)>dfs=[&](int y,int x){
      s[y][x]=1;
      int r[]={-1,0,1,0};
      int c[]={0,1,0,-1};
      int k=1;
      for(int l=0;l<4;l++){
        int u=y+r[l],v=x+c[l];
        if(u>=0&&u<n&&v>=0&&v<m&&!s[u][v]&&a[u][v]==a[y][x])
          k+=dfs(u,v);
      }
      return k;
    };
    vii r;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(!s[i][j]&&a[i][j]!='.')
          r.emplace_back(-dfs(i,j),a[i][j]);
    sort(r.begin(),r.end());
    cout<<"Problem "<<T<<":\n";
    for(ii x:r){
      int u,v;
      tie(u,v)=x;
      cout<<char(v)<<" "<<-u<<endl;
    }
  }
}
