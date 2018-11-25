// https://codeforces.com/contest/1056/problem/D
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  int n,p;
  cin>>n;
  vvi g(n);
  for(int i=0;i<n-1;i++){
    cin>>p;
    g[p-1].push_back(i+1);
  }
  vi c(n);
  function<void(int)> dfs=[&](int u){
    int k=0;
    for (int v:g[u]){
      dfs(v);
      k+=c[v];
    }
    c[u]=max(k,1);
  };
  dfs(0);
  sort(c.begin(),c.end());
  for (int i=0;i<n;i++)cout<<c[i]<<" \n"[i==n-1];
}
