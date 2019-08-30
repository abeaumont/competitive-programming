// https://cses.fi/problemset/task/1160/
#include <bits/stdc++.h>

using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,q,u,v;
  cin>>n>>q;
  vi a(n),b(n),c(n),d(n),p(n,-2);
  for (int i=0;i<n;i++) {
    cin>>a[i];
    a[i]--;
  }
  for (int i=0;i<n;i++) b[a[i]]++;
  vvi paths;
  vi cycles;
  int l=0;
  function<void(int,int)> dfs=[&](int u,int k) {
    if (c[u]) {
      if (c[u]==k) {
        cycles.push_back(u);
        paths.push_back(vi());
        l=k;
        return;
      }
      l=c[u];
      return;
    }
    c[u]=k;
    dfs(a[u],k);
    c[u]=l;
    if (k!=l||p[a[u]]>=-1) {
      p[u] = a[u];
      d[u] = d[a[u]]+1;
    } else {
      paths[l-1].push_back(u);
      if (u==cycles[l-1]) p[u]=-1;
    }
  };
  int k=1;
  for (int i=0;i<n;i++) {
    if (!b[i]&&!c[i]) dfs(i,k);
    if (l==k) k++;
  }
  for (int i=0;i<n;i++) {
    if (!c[i]) dfs(i,k);
    if (l==k) k++;
  }
  for (int i=0;i<paths.size();i++) {
    reverse(paths[i].begin(),paths[i].end());
    for (int j=0;j<paths[i].size();j++) b[paths[i][j]]=j;
  }
  vvi ancestors;
  ancestors.push_back(vi(n+1));
  for (int i=1;i<=n;i++) ancestors[0][i]=max(0,p[i-1]+1);
  for (int i=1,j=1;i<n;i*=2,j++){
    ancestors.push_back(vi(n+1));
    for (int k=1;k<=n;k++)
      ancestors[j][k]=ancestors[j-1][ancestors[j-1][k]];
  }
  while (q--) {
    cin>>u>>v;
    u--;v--;
    if (c[u]==c[v]) {
      if (!d[u]&&!d[v]) {
        int k=b[v]-b[u];
        if (k<0) k+=paths[c[u]-1].size();
        cout<<k<<endl;
      } else if (!d[u]) cout<<-1<<endl;
      else if (!d[v]) {
        int x=d[u];
        while (d[u]) {
          int z=d[u];
          int j=1,i=0;
          while (j*2<z) {
            i++;
            j<<=1;
          }
          u=ancestors[i][u+1]-1;
        }
        int k=b[v]-b[u];
        if (k<0) k+=paths[c[u]-1].size();
        cout<<k+x<<endl;
      } else if (d[u]>d[v]) {
        int x=d[u]-d[v];
        while (d[u]>d[v]) {
          int z=d[u]-d[v];
          int j=1,i=0;
          while (j*2<z) {
            i++;
            j<<=1;
          }
          u=ancestors[i][u+1]-1;
        }
        if (u==v) cout<<x<<endl;
        else cout<<-1<<endl;
      } else if (d[v]>d[u]) cout<<-1<<endl;
      else if (u==v) cout<<0<<endl;
      else cout<<-1<<endl;
    } else cout<<-1<<endl;
  }
}
