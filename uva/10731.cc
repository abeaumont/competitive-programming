// https://uva.onlinejudge.org/external/107/10731.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int T=0;;T++){
    int n,l,u,v;
    cin>>l;
    if(!l)break;
    vi m(128);
    vii e;
    n=0;
    for(int i=0;i<l;i++){
      vi x;
      char c;
      for(int j=0;j<5;j++){
        cin>>c;
        if(!m[c])m[c]=++n;
        x.push_back(m[c]-1);
      }
      cin>>c;
      if(!m[c])m[c]=++n;
      u=m[c]-1;
      for(int v:x)
        if(u!=v)e.emplace_back(u,v);
    }
    vi r(n);
    for(int i=0;i<128;i++)
      if(m[i])
        r[m[i]-1]=i;
    vvi g(n),h(n),c;
    for(ii x:e){
      tie(u,v)=x;
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
      c.back().push_back(i);
      for(int j:h[i])
        if(!t[j])dfs2(j);
    };
    for(int i=0;i<a.size();i++)
      if(!t[a[i]]){
        c.push_back(vi());
        dfs2(a[i]);
      }
    vs q;
    for(vi&x:c){
      vi p;
      for(int i:x)p.push_back(r[i]);
      sort(p.begin(),p.end());
      stringstream o;
      for(int i=0;i<p.size();i++){
        o<<char(p[i]);
        if(i<p.size()-1)o<<" ";
      }
      q.push_back(o.str());
    }
    sort(q.begin(),q.end());
    if(T)cout<<"\n";
    for(auto &s:q)cout<<s<<"\n";
  }
}
