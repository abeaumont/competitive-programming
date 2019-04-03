// https://uva.onlinejudge.org/external/1/168.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    string s;
    getline(cin,s);
    if(s[0]=='#')break;
    vii e;
    vi m(128);
    int n=0,i=0,u,v,w,k;
    for(;;){
      char x=s[i],y;
      if(!m[x])m[x]=++n;
      u=m[x]-1;
      i++;
      for(;s[i]!=';'&&s[i]!='.';i++){
        if(s[i]==':')continue;
        x=s[i];
        if(!m[x])m[x]=++n;
        w=m[x]-1;
        e.emplace_back(u,w);
      }
      if(s[i]==';')i++;
      else{
        stringstream in(s.substr(i+1));
        in>>x>>y>>k;
        u=m[x]-1;
        w=m[y]-1;
        break;
      }
    }
    vi r(n);
    for(int i=0;i<128;i++)
      if(m[i])
        r[m[i]-1]=i;
    vvi g(n);
    for(ii x:e){
      tie(i,v)=x;
      g[i].push_back(v);
    }
    vi t(n);
    for(i=0;;i++){
      int z=u;
      for(int v:g[u])
        if(v!=w&&!t[v]){
          u=v;
          break;
        }
      w=z;
      if(w==u)break;
      if(i%k==k-1){
        t[w]=1;
        cout<<char(r[w])<<" ";
      }
    }
    cout<<"/"<<char(r[u])<<"\n";
  }
}
