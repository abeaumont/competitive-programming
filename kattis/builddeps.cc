// https://open.kattis.com/problems/builddeps
#include<bits/stdc++.h>
using namespace std;
using msi=map<string,int>;
using vi=vector<int>;
using vs=vector<string>;
using vvi=vector<vi>;
int main(){
  int n;
  cin>>n;
  vvi g(n);
  msi m;
  vs mi(n);
  string s;
  getline(cin,s);
  int w=0;
  for(int i=0;i<n;i++){
    getline(cin,s);
    stringstream in(s);
    in>>s;
    s=s.substr(0, s.size()-1);
    int u=m.count(s)?m[s]:m[s]=w++;
    mi[u]=s;
    while(in>>s){
      int v=m.count(s)?m[s]:m[s]=w++;
      mi[v]=s;
      g[v].push_back(u);
    }
  }
  vi t(n);
  vi o;
  function<void(int)>dfs=[&](int u){
    t[u]++;
    for(int v:g[u]){
      if(t[v])continue;
      dfs(v);
    }
    o.push_back(u);
  };
  getline(cin, s);
  dfs(m[s]);
  reverse(o.begin(),o.end());
  for(int u:o)cout<<mi[u]<<endl;
}
