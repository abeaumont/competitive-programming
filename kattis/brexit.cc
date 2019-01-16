// https://open.kattis.com/problems/brexit
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using si=unordered_set<int>;
using vsi=vector<si>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int c,p,x,l,u,v;
  cin>>c>>p>>x>>l;
  x--;l--;
  vsi a(c);
  vi b(c),d(c),e(c),f;
  for(int i=0;i<p;i++){
    cin>>u>>v;
    u--;v--;
    a[u].insert(v);
    a[v].insert(u);
  }
  for(int i=0;i<c;i++)b[i]=a[i].size();
  f.push_back(l);
  while(!f.empty()){
    u=f.back();
    f.pop_back();
    if(e[u])continue;
    e[u]=1;
    if(u==x)break;
    for(int v:a[u]){
      a[v].erase(u);
      d[v]++;
      if(d[v]*2>=b[v])f.push_back(v);
    }
  }
  cout<<(e[x]?"leave\n":"stay\n");
}
