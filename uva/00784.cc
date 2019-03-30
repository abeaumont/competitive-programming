// https://uva.onlinejudge.org/external/7/784.pdf
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  string s;
  getline(cin,s);
  while(t--){
    vs a;
    for(;;){
      getline(cin,s);
      a.push_back(s);
      if(s[0]=='_')break;
    }
    function<void(int,int)>dfs=[&](int y,int x){
      a[y][x]='#';
      int r[]={-1,0,1,0};
      int c[]={0,1,0,-1};
      for(int i=0;i<4;i++){
        int u=y+r[i],v=x+c[i];
        if(a[u][v]==' ')dfs(u,v);
      }
    };
    for(int i=0;i<a.size();i++)
      for(int j=0;j<a[i].size();j++)
        if(a[i][j]=='*')
          dfs(i,j);
    for(auto s:a)cout<<s<<"\n";
  }
}
