// https://uva.onlinejudge.org/external/2/291.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vii=vector<ii>;
using vvi=vector<vi>;
using sii=set<ii>;
int main(){
  vvi g(6);
  g[0].push_back(1);
  g[0].push_back(2);
  g[0].push_back(4);
  g[1].push_back(0);
  g[1].push_back(2);
  g[1].push_back(4);
  g[2].push_back(0);
  g[2].push_back(1);
  g[2].push_back(3);
  g[2].push_back(4);
  g[3].push_back(2);
  g[3].push_back(4);
  g[4].push_back(0);
  g[4].push_back(1);
  g[4].push_back(2);
  g[4].push_back(3);
  sii t;
  vi p(1,0);
  function<void(int)>s=[&](int u){
    if(p.size()==9){
      for(int x:p)cout<<x+1;
      cout<<endl;
    }
    for(int v:g[u]){
      int a=min(u,v),b=max(u,v);
      if(!t.count({a,b})){
        t.insert({a,b});
        p.push_back(v);
        s(v);
        t.erase({a,b});
        p.pop_back();
      }
    }
  };
  s(0);
}
