// https://uva.onlinejudge.org/external/105/10507.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  int n,m;
  while(cin>>n>>m){
    int e=0;
    vvi a(n);
    vi b(n),d(128,-1);
    string s;
    cin>>s;
    for(char c:s){
      if(d[c]==-1)d[c]=e++;
      b[d[c]]=1;
    }
    for(int i=0;i<m;i++){
      cin>>s;
      if(d[s[0]]==-1)d[s[0]]=e++;
      if(d[s[1]]==-1)d[s[1]]=e++;
      int u=d[s[0]],v=d[s[1]];
      a[u].push_back(v);
      a[v].push_back(u);
    }
    int k=0;
    while(1){
      vi c;
      for(int i=0;i<n;i++)
        if(!b[i]){
          int l=0;
          for(int v:a[i])l+=b[v];
          if(l>=3)c.push_back(i);
        }
      if(c.empty())break;
      for(int x:c)b[x]=1;
      k++;
    }
    int o=1;
    for(int x:b)if(!x)o=0;
    if(o)cout<<"WAKE UP IN, "<<k<<", YEARS\n";
    else cout<<"THIS BRAIN NEVER WAKES UP\n";
  }
}
