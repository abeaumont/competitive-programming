// https://uva.onlinejudge.org/external/8/852.pdf
#include<bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
using vvb=vector<vb>;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n=9;
  cin>>t;
  while(t--){
    vs a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvb s(n, vb(n));
    bool b,w;
    int c,x=0,y=0;
    function<void(int,int)>dfs=[&](int y,int x){
      s[y][x]=1;
      c++;
      int r[]={-1,0,1,0};
      int c[]={0,1,0,-1};
      for(int i=0;i<4;i++){
        int u=y+r[i],v=x+c[i];
        if(u>=0&&u<n&&v>=0&&v<n){
          if(a[u][v]=='O')w=1;
          else if(a[u][v]=='X')b=1;
          else if(!s[u][v])dfs(u,v);
        }
      }
    };
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(a[i][j]=='O')x++;
        else if(a[i][j]=='X')y++;
        else if(!s[i][j]){
          c=b=w=0;
          dfs(i,j);
          if(w&&!b)x+=c;
          else if(!w&&b)y+=c;
        }
    cout<<"Black "<<y<<" White "<<x<<"\n";
  }
}
