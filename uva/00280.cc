// https://uva.onlinejudge.org/external/2/280.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  while(1){
    int n,u,v,c;
    cin>>n;
    if(!n)break;
    vvi g(n);
    while(1){
      cin>>u;
      if(!u)break;
      u--;
      while(1){
        cin>>v;
        if(!v)break;
        v--;
        g[u].push_back(v);
      }
    }
    cin>>c;
    for(int i=0;i<c;i++){
      vi s(n);
      function<void(int)>dfs=[&](int i){
        s[i]=1;
        for(int j:g[i])
          if(!s[j])dfs(j);
      };
      cin>>u;u--;
      for(int j:g[u])dfs(j);
      vi a;
      for(int i=0;i<n;i++)
        if(!s[i])a.push_back(i);
      cout<<a.size();
      for(int i:a)cout<<" "<<i+1;
      cout<<endl;
    }
  }
}
