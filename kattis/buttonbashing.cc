// https://open.kattis.com/problems/buttonbashing
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using si=set<int>;
using vsi=vector<si>;
using qii=queue<ii>;
const int T=3600;
int main(){
  int q,n,t;
  cin>>q;
  while(q--){
    cin>>n>>t;
    vi a(n);
    vsi g(T+1);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<=T;i++)
      for(int b:a)
        g[i].insert(max(0,min(T,i+b)));
    qii q;
    vi d(T+1,-1);
    q.push({0,0});
    while(!q.empty()){
      int u,k;
      tie(u,k)=q.front();
      q.pop();
      if(d[u]>=0)continue;
      d[u]=k;
      if(u==t)break;
      for(int v:g[u]){
        if(d[v]>=0)continue;
        q.push({v,k+1});
      }
    }
    for(int k=t;k<=T;k++)
      if(d[k]>=0){
        cout<<d[k]<<" "<<k-t<<endl;
        break;
      }
  }
}
