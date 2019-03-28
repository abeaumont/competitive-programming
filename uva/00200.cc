// https://uva.onlinejudge.org/external/2/200.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    string s;
    getline(cin,s);
    if(s.empty())break;
    vs t;
    for(;;){
      if(s[0]=='#')break;
      t.push_back(s);
      getline(cin,s);
    }
    vi p(128),m(128);
    string q;
    for(auto &s:t){
      for(auto c:s){
        p[c]++;
      }
    }
    int n=0;
    for(int i='A';i<='Z';i++)
      if(p[i]){
        m[i]=n++;
        q.push_back(i);
      }
    vvi g(n);
    for(int i=0;i<t.size()-1;i++){
      string &a=t[i],&b=t[i+1];
      for(int j=0;j<min(a.size(),b.size());j++)
        if(a[j]!=b[j]){
          g[m[a[j]]].push_back(m[b[j]]);
          break;
        }
    }
    vi w(n),x;
    function<void(int)>dfs=[&](int u){
      w[u]=1;
      for(int v:g[u])
        if(!w[v])
          dfs(v);
      x.push_back(u);
    };
    for(int i=0;i<n;i++)
      if(!w[i])
        dfs(i);
    reverse(x.begin(),x.end());
    for(int i=0;i<n;i++)
      cout<<q[x[i]];
    cout<<"\n";
  }
}
