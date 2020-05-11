// https://www.codechef.com/DEC18A/problems/DLDAG
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using iii=tuple<int,int,int>;
using vi=vector<int>;
using si=unordered_set<int>;
using vvi=vector<vi>;
using vsi=vector<si>;
using vii=vector<ii>;
using pq=priority_queue<ii>;
using pqiii=priority_queue<iii>;
using pqr=priority_queue<iii,vector<iii>,greater<iii>>;

int n,m,u,v;
vvi g,h;

void f1(const vvi& g, const vsi& h, vvi &r){
  int n=g.size();
  vi c,d(n,-10000000),s(n);
  function<void(int,int)>dfs=[&](int u, int k){
    if(d[u]!=-10000000)return;
    d[u]=k;
    for(int v:g[u]){
      s[v]++;
      if(d[v]==-10000000)
        dfs(v,k+1);
      d[u]=min(d[u],d[v]-1) ;
    }
  };
  for(int i=0;i<n;i++) if(h[i].empty()) dfs(i,0);
  pqr q;
  for(int i=0;i<n;i++)
    if(!s[i]) q.push({0,0,i});
  int i=1;
  while (!q.empty()) {
    int k,e,u;
    tie(k,e,u)=q.top();
    q.pop();
    c.push_back(u);
    for(int v:g[u]){
      s[v]--;
      if (!s[v]) q.push({i,0,v});
    }
    i++;
  }
  reverse(c.begin(), c.end());
  i=0;
  while(i<c.size()-1){
    int u = c[i];
    int v = c[i+1];
    if (h[u].count(v)){
      r.push_back({u});
      i++;
    } else {
      r.push_back({u, v});
      i += 2;
    }
  }
  if (i<c.size())
    r.push_back({c[i]});
}

void f2(const vvi& g, const vsi& h, vvi &r){
  int n=g.size();
  vi c,d(n,-10000000),s(n);
  function<void(int,int)>dfs=[&](int u, int k){
    if(d[u]!=-10000000)return;
    d[u]=k;
    for(int v:g[u]){
      s[v]++;
      if(d[v]==-10000000)
        dfs(v,k+1);
      d[u]=min(d[u],d[v]-1) ;
    }
  };
  for(int i=0;i<n;i++) if(h[i].empty()) dfs(i,0);
  pqr q;
  for(int i=0;i<n;i++)
    if(!s[i]) q.push({d[i],0,i});
  int i=1;
  while (!q.empty()) {
    int k,e,u;
    tie(k,e,u)=q.top();
    q.pop();
    c.push_back(u);
    for(int v:g[u]){
      s[v]--;
      if (!s[v]) q.push({d[v],i,v});
    }
    i++;
  }
  reverse(c.begin(), c.end());
  i=0;
  while(i<c.size()-1){
    int u = c[i];
    int v = c[i+1];
    if (h[u].count(v)){
      r.push_back({u});
      i++;
    } else {
      r.push_back({u, v});
      i += 2;
    }
  }
  if (i<c.size())
    r.push_back({c[i]});
}

void f3(const vvi& g, const vsi& h, vvi &r){
  int n=g.size();
  vi c,d(n,-10000000),s(n);
  function<void(int,int)>dfs=[&](int u, int k){
    if(d[u]!=-10000000)return;
    d[u]=k;
    for(int v:g[u]){
      s[v]++;
      if(d[v]==-10000000)
        dfs(v,k+1);
      d[u]=min(d[u],d[v]-1) ;
    }
  };
  for(int i=0;i<n;i++) if(h[i].empty()) dfs(i,0);
  pqr q;
  for(int i=0;i<n;i++)
    if(!s[i]) q.push({d[i],rand()*10,i});
  int i=1;
  while (!q.empty()) {
    int k,e,u;
    tie(k,e,u)=q.top();
    q.pop();
    c.push_back(u);
    for(int v:g[u]){
      s[v]--;
      if (!s[v]) q.push({d[v],i*(1+rand()%2),v});
    }
    i++;
  }
  reverse(c.begin(), c.end());
  i=0;
  while(i<c.size()-1){
    int u = c[i];
    int v = c[i+1];
    if (h[u].count(v)){
      r.push_back({u});
      i++;
    } else {
      r.push_back({u, v});
      i += 2;
    }
  }
  if (i<c.size())
    r.push_back({c[i]});
}

int sorted(vvi &r) {
  int c=0;
  vi d(n), s(n, -1);
  pq q;
  function<void(int,int)>dfs=[&](int u, int k){
    if(s[u]!=-1)return;
    s[u]=0;
    d[u]=k;
    for(int v:g[u]){
      if(s[v]==-1) dfs(v,k+1);
      s[u]++;
    }
    if(!s[u])q.push({k,u});
  };
  for(int i=0;i<n;i++) if(s[i]==-1) dfs(i,0);
  while (!q.empty()){
    int u=get<1>(q.top()),v=-1;
    q.pop();
    if (!q.empty()) {
      v = get<1>(q.top());
      q.pop();
      r.push_back({u, v});
      c++;
    }else r.push_back({u});
    for (int w:h[u]){
      s[w]--;
      if(!s[w])q.push({d[w],w});
    }
    if(v!=-1)
      for (int w:h[v]){
        s[w]--;
        if(!s[w])q.push({d[w],w});
      }
  }
  return c;
}

int sorted_fix(vvi &r) {
  int c=0;
  vi d(n, -1), s(n, -1);
  pq q;
  function<void(int,int)>dfs=[&](int u, int k){
    if(s[u]!=-1)return;
    s[u]=0;
    for(int v:g[u]){
      if(s[v]==-1) dfs(v,k+1);
      s[u]++;
    }
  };
  for(int i=0;i<n;i++) if(s[i]==-1) dfs(i,0);
  function<void(int,int)>dfs2=[&](int u, int k){
    if(d[u]!=-1)return;
    d[u]=k;
    for(int v:g[u]){
      if(d[v]==-1)
        dfs2(v,k+1);
      d[u]=min(d[u],d[v]-1) ;
    }
    if(!s[u])q.push({d[u],u});
  };
  for(int i=0;i<n;i++) if(h[i].empty()) dfs2(i,0);
  while (!q.empty()){
    int u=get<1>(q.top()),v=-1;
    q.pop();
    if (!q.empty()) {
      v = get<1>(q.top());
      q.pop();
      r.push_back({u, v});
      c++;
    }else r.push_back({u});
    for (int w:h[u]){
      s[w]--;
      if(!s[w])q.push({d[w],w});
    }
    if(v!=-1)
      for (int w:h[v]){
        s[w]--;
        if(!s[w])q.push({d[w],w});
      }
  }
  return c;
}

int sorted2(vvi &r) {
  int c=0;
  vi d(n), s(n, -1);
  pqiii q;
  function<void(int,int)>dfs=[&](int u, int k){
    if(s[u]!=-1)return;
    s[u]=0;
    d[u]=k;
    for(int v:g[u]){
      if(s[v]==-1) dfs(v,k+1);
      s[u]++;
    }
    if(!s[u])q.push({k,h[u].size(),u});
  };
  for(int i=0;i<n;i++) if(s[i]==-1) dfs(i,0);
  while (!q.empty()){
    int u=get<2>(q.top()),v=-1;
    q.pop();
    if (!q.empty()) {
      v = get<2>(q.top());
      q.pop();
      r.push_back({u, v});
      c++;
    }else r.push_back({u});
    for (int w:h[u]){
      s[w]--;
      if(!s[w])q.push({d[w],h[w].size(),w});
    }
    if(v!=-1)
      for (int w:h[v]){
        s[w]--;
        if(!s[w])q.push({d[w],h[w].size(),w});
      }
  }
  return c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  g=vvi(n);
  h=vvi(n);
  vsi l(n);
  for(int i=0;i<m;i++){
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
    h[v].push_back(u);
    l[v].insert(u);
  }
  vvi r;
  sorted_fix(r);
  vvi r2;
  f1(g,l,r2);
  if(r2.size()<r.size()) swap(r, r2);
  r2 = vvi();
  f2(g,l,r2);
  if(r2.size()<r.size()) swap(r, r2);
  r2 = vvi();
  f3(g,l,r2);
  if(r2.size()<r.size()) swap(r, r2);
  
  cout<<r.size()<<"\n";
  for (auto x:r){
    cout<<x.size();
    for(int y:x)cout<<" "<<y+1;
    cout<<"\n";
  }
}
