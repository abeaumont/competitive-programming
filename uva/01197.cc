// https://uva.onlinejudge.org/external/11/1197.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    int n,m,k,u,v;
    cin>>n>>m;
    if(!n)break;
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
      cin>>k>>u;
      for(int j=1;j<k;j++){
        cin>>v;
        unite(u,v);
      }
    }
    k=0;
    for(int i=0;i<n;i++)
      k+=find(i)==find(0);
    cout<<k<<"\n";
  }
}
