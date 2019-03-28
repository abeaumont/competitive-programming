// https://uva.onlinejudge.org/external/1/124.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using qi=queue<int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(int T=0;;T++){
    string s;
    getline(cin,s);
    if(s.empty())break;
    vi m(128);
    stringstream in(s);
    char x,y;
    int n=0;
    vi c;
    while(in>>x){
      m[x]=n++;
      c.push_back(x);
    }
    sort(c.begin(),c.end());
    for(int i=0;i<n;i++)
      m[c[i]]=i;
    vvi g(n);
    vi a(n),b;
    getline(cin,s);
    in = stringstream(s);
    while(in>>x>>y){
      int u=m[x],v=m[y];
      g[u].push_back(v);
      a[v]++;
    }
    string t;
    vi r(n);
    function<void(int)>f=[&](int u){
      r[u]=1;
      t.push_back(c[u]);
      if(t.size()==n)cout<<t<<"\n";
      for(int v:g[u])a[v]--;
      for(int i=0;i<n;i++)
        if(!a[i]&&!r[i])f(i);
      for(int v:g[u])a[v]++;
      t.pop_back();
      r[u]=0;
    };
    if(T)cout<<"\n";
    for(int i=0;i<n;i++)
      if(!a[i])
        f(i);
  }
}
