// https://uva.onlinejudge.org/external/7/782.pdf
#include<bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
using vvb=vector<vb>;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  string s;
  cin>>t;
  getline(cin,s);
  while(t--){
    vs a;
    vvb b;
    for(;;){
      getline(cin,s);
      s.append(string(81-s.size(),' '));
      a.push_back(s);
      if(s[0]=='_')break;
      b.push_back(vb(81));
    }
    function<void(int,int,int)>dfs=[&](int y,int x, int k){
      b[y][x]=1;
      int r[]={-1,0,1,0};
      int c[]={0,1,0,-1};
      for(int i=0;i<4;i++){
        int u=y+r[i],v=x+c[i];
        if(u>=0&&u<b.size()&&v>=0&&v<b[u].size()){
          if(a[u][v]=='X')a[y][x]='#';
          else if(!b[u][v]&&a[u][v]==' ')dfs(u,v,k);
        }
      }
    };
    int m,y,x;
    for(int i=0;i<a.size()-1;i++)
      for(int j=0;j<a[i].size();j++)
        if(a[i][j]=='*'){
          a[i][j]=' ';
          y=i;x=j;
        }else if(a[i][j]!=' ')m=a[i][j];
    dfs(y,x,m);
    for(auto s:a){
      int i=80;
      while(s[i--]==' ');
      cout<<s.substr(0,i+2)<<"\n";
    }
  }
}
