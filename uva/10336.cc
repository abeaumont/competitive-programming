// https://uva.onlinejudge.org/external/103/10336.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
using vi=vector<int>;
using vs=vector<string>;
using vb=vector<bool>;
using vvb=vector<vb>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n,m;
  cin>>t;
  for(int T=1;T<=t;T++){
    cin>>n>>m;
    vs a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvb s(n,vb(m));
    function<void(int,int)>dfs=[&](int y,int x){
      s[y][x]=1;
      int r[]={-1,0,1,0};
      int c[]={0,1,0,-1};
      for(int i=0;i<4;i++){
        int u=y+r[i],v=x+c[i];
        if(u>=0&&u<n&&v>=0&&v<m&&!s[u][v]&&a[u][v]==a[y][x])
          dfs(u,v);
      }
    };
    vi r(128);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(!s[i][j]){
          dfs(i,j);
          r[a[i][j]]++;
        }
    vii b;
    for(int i=0;i<128;i++)
      if(r[i])
        b.push_back({-r[i],i});
    sort(b.begin(),b.end());
    cout<<"World #"<<T<<"\n";
    for(ii x:b){
      int c,d;
      tie(c,d)=x;
      cout<<char(d)<<": "<<-c<<"\n";
    }
  }
}
