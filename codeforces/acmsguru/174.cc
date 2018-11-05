// https://codeforces.com/problemsets/acmsguru/problem/99999/174
#include <bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using iiii=tuple<ii,ii>;
using vi=vector<int>;
using mii=map<ii,int>;
using siiii=set<iiii>;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m,x1,y1,x2,y2;
  cin>>m;
  vi p(m+1),s(m+1,1);
  for(int i=0;i<=m;i++)p[i]=i;
  mii n;
  function<int(int)> find=[&](int x){
    assert(x);
    if(p[x]==x)return x;
    return p[x]=find(p[x]);
  };
  auto join=[&](int u, int v){
    u=find(u);
    v=find(v);
    if(u==v)return;
    if(s[v]>s[u])swap(u,v);
    s[u]+=s[v];
    p[v]=u;
  };
  siiii t;
  for(int i=1;i<=m;i++){
    cin>>x1>>y1>>x2>>y2;
    ii k1={x1,y1},k2={x2,y2};
    if(k1==k2||t.count({k2,k1})||t.count({k1,k2})){
      cout<<i<<endl;
      return 0;
    }
    t.insert({k1,k2});
    int a=n[k1],b=n[k2];
    if(a&&b){
      int pa=find(a),pb=find(b);
      if (pa==pb) {
        cout<<i<<endl;
        return 0;
      }
      join(pa,pb);
      continue;
    }
    if(a){
      join(i,a);
      n[k2]=i;
      continue;
    }
    if(b){
      join(i,b);
      n[k1]=i;
      continue;
    }
    n[k1]=n[k2]=i;
  }
  cout<<0<<endl;
}
