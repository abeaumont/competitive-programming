// https://uva.onlinejudge.org/external/7/785.pdf
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    string s;
    vs a;
    for(;;){
      getline(cin,s);
      if(cin.eof())return 0;
      a.push_back(s);
      if(s[0]=='_')break;
    }
    function<void(int,int,int)>dfs=[&](int y,int x, int k){
      a[y][x]=k;
      int r[]={-1,0,1,0};
      int c[]={0,1,0,-1};
      for(int i=0;i<4;i++){
        int u=y+r[i],v=x+c[i];
        if(u>=0&&u<a.size()-2&&v>=0&&v<a[u].size()&&a[u][v]==' ')
          dfs(u,v,k);
      }
    };
    int m=0;
    for(int i=0;i<a.size()-1;i++)
      for(int j=0;j<a[i].size();j++)
        if(a[i][j]!=' '){
          if(!m)m=a[i][j];
          else if(a[i][j]!=m)dfs(i,j,a[i][j]);
        }
    for(auto s:a)cout<<s<<"\n";
  }
}
