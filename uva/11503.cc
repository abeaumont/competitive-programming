// https://uva.onlinejudge.org/external/115/11503.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vii=vector<ii>;
using msi=unordered_map<string,int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,m,u,v;
  cin>>t;
  while(t--){
    cin>>m;
    vii e(m);
    msi x;
    int n=0;
    for(int i=0;i<m;i++){
      string r,s;
      cin>>r>>s;
      if(!x.count(r))x[r]=n++;
      if(!x.count(s))x[s]=n++;
      e[i]={x[r],x[s]};
    }
    vi s=vi(n, 1),p=vi(n);
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
    for(int i=0;i<m;i++){
      tie(u,v)=e[i];
      unite(u,v);
      cout<<s[find(u)]<<"\n";;
    }
  }
}
