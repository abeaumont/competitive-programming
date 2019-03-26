// https://uva.onlinejudge.org/external/4/469.pdf
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  string s;
  cin>>t;
  getline(cin,s);
  getline(cin,s);
  for(int T=0;T<t;T++){
    if(T)cout<<"\n";
    vs a;
    for(;;){
      getline(cin,s);
      if(s.empty())break;
      if(s[0]!='L'&&s[0]!='W')break;
      a.push_back(s);
    }
    int n=a.size();
    if(!n)continue;
    int m=a[0].size();
    vvi c(n,vi(m));
    function<void(int,int,int)>dfs=[&](int y,int x,int k){
      c[y][x]=k;
      if(x>0&&!c[y][x-1]&&a[y][x-1]=='W')dfs(y,x-1,k);
      if(y>0&&x>0&&!c[y-1][x-1]&&a[y-1][x-1]=='W')dfs(y-1,x-1,k);
      if(y>0&&!c[y-1][x]&&a[y-1][x]=='W')dfs(y-1,x,k);
      if(y>0&&x<m-1&&!c[y-1][x+1]&&a[y-1][x+1]=='W')dfs(y-1,x+1,k);
      if(x<m-1&&!c[y][x+1]&&a[y][x+1]=='W')dfs(y,x+1,k);
      if(y<n-1&&x<m-1&&!c[y+1][x+1]&&a[y+1][x+1]=='W')dfs(y+1,x+1,k);
      if(y<n-1&&!c[y+1][x]&&a[y+1][x]=='W')dfs(y+1,x,k);
      if(y<n-1&&x>0&&!c[y+1][x-1]&&a[y+1][x-1]=='W')dfs(y+1,x-1,k);
    };
    int k=1;
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(!c[i][j]&&a[i][j]=='W'){
          dfs(i,j,k++);
        }
    vi b(k);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(c[i][j])
          b[c[i][j]]++;
    for(;;){
      if(s.empty())break;
      stringstream in(s);
      int y,x;
      in>>y>>x;
      y--;x--;
      cout<<b[c[y][x]]<<endl;
      getline(cin,s);
    }
  }
}
