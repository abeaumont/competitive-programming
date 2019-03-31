// https://uva.onlinejudge.org/external/117/11709.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using msi=unordered_map<string,int>;
int main(){
  for(;;){
    int n,m,u,v;
    string r;
    cin>>n>>m;
    if(!n)break;
    getline(cin,r);
    msi x;
    int k=0;
    for(int i=0;i<n;i++){
      getline(cin,r);
      x[r]=k++;
    }
    vvi g(n),h(n),c;
    for(int i=0;i<m;i++){
      getline(cin,r);
      u=x[r];
      getline(cin,r);
      v=x[r];
      g[u].push_back(v);
      h[v].push_back(u);
    }
    vi a,s(n),t(n);
    function<void(int)> dfs1=[&](int i){
      s[i]=1;
      for(int j:g[i])
        if(!s[j])dfs1(j);
      a.push_back(i);
    };
    for(int i=0;i<n;i++)
      if(!s[i])dfs1(i);
    reverse(a.begin(),a.end());
    function<void(int)> dfs2=[&](int i){
      t[i]=1;
      for(int j:h[i])
        if(!t[j])dfs2(j);
    };
    k=0;
    for(int i=0;i<a.size();i++)
      if(!t[a[i]]){
        k++;
        dfs2(a[i]);
      }
    cout<<k<<"\n";
  }
}
