// https://uva.onlinejudge.org/external/5/599.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  int t;
  cin>>t;
  string s;
  getline(cin,s);
  while(t--){
    vvi g(26);
    while(1){
      getline(cin,s);
      if(s[0]=='*')break;
      int u=s[1]-'A',v=s[3]-'A';
      g[u].push_back(v);
      g[v].push_back(u);
    }
    getline(cin,s);
    vi n(26);
    for(int i=0;i<s.size();i+=2)n[s[i]-'A']=1;
    vi c(26);
    function<void(int)>dfs=[&](int u){
      c[u]=1;

      for(int v:g[u])
        if(!c[v])
          dfs(v);
    };
    int a=0,b=0;
    for(int i=0;i<26;i++)
      if(n[i]&&!c[i])
        if(g[i].empty())a++;
        else{
          dfs(i);
          b++;
        }
    cout<<"There are "<<b<<" tree(s) and "<<a<<" acorn(s).\n";
  }
}
