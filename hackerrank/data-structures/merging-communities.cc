// https://www.hackerrank.com/challenges/merging-communities
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m,u,v;
  cin>>n>>m;
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
    char q;
    cin>>q>>u;
    u--;
    if(q=='M'){
      cin>>v;
      v--;
      unite(u,v);
    }else cout<<s[find(u)]<<"\n";
  }
}
