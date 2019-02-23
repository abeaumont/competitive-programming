// https://uva.onlinejudge.org/external/4/459.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  int t;
  string s;
  cin>>t;
  getline(cin, s);
  getline(cin, s);
  while(t--){
    int n,u,v,c=0;
    getline(cin, s);
    n=s[0]-'A'+1;
    vvi g(n);
    while(1){
      getline(cin,s);
      if(s.empty())break;
      u=s[0]-'A';
      v=s[1]-'A';
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vi s(n);
    function<void(int)>dfs=[&](int i){
      s[i]=1;
      for(int j:g[i])
        if(!s[j])
          dfs(j);
    };
    for(int i=0;i<n;i++)
      if(!s[i]){
        c++;
        dfs(i);
      }
    cout<<c<<"\n";
    if(t)cout<<"\n";
  }
}
