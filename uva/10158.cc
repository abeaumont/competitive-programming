// https://uva.onlinejudge.org/external/101/10158.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int n,c,u,v;
  cin>>n;
  vi s=vi(n, 1),p=vi(n),e=vi(n,-1);
  for(int i=0;i<n;i++)p[i]=i;
  function<int(int)>find=[&](int i){
    if(i==p[i])return i;
    return p[i]=find(p[i]);
  };
  function<void(int,int)>unite=[&](int i, int j){
    i=find(i);
    j=find(j);
    if(i==j)return;
    if(s[i]<s[j])swap(i,j);
    s[i]+=s[j];
    p[j]=i;
  };
  while(1){
    cin>>c>>u>>v;
    if(!c)break;
    if(c==1){
      int a=find(u),b=find(v);
      if(e[a]==b){
        cout<<"-1\n";
        continue;
      }
      if(a==b)continue;
      unite(a,b);
      int p=find(a);
      if(e[a]!=-1&&e[b]!=-1){
        if(e[a]!=e[b]){
          unite(e[a],e[b]);
          int q=find(e[a]);
          e[e[a]]=e[e[b]]=p;
          e[a]=e[b]=q;
        }
      }else if(e[a]!=-1){
        e[e[a]]=p;
        e[p]=e[a];
      }else if(e[b]!=-1){
        e[e[b]]=p;
        e[p]=e[b];
      }
    }else if(c==2){
      int a=find(u),b=find(v);
      if(a==b){
        cout<<"-1\n";
        continue;
      }
      if(e[a]==b)continue;
      if(e[a]!=-1)unite(e[a],b);
      if(e[b]!=-1)unite(e[b],a);
      a=find(a);b=find(b);
      e[a]=b;e[b]=a;
    }else if(c==3)cout<<(find(u)==find(v))<<"\n";
    else cout<<(e[find(u)]==find(v))<<"\n";
  }
}
