// https://uva.onlinejudge.org/external/7/793.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int t,n,u,v;
  cin>>t;
  while(t--){
    cin>>n;
    string l;
    getline(cin,l);
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
    int a=0,b=0;
    while(1){
      getline(cin,l);
      if(l.empty())break;
      stringstream in(l);
      char q;
      in>>q>>u>>v;
      u--;v--;
      if(q=='c')unite(u,v);
      else if(find(u)==find(v))a++;
      else b++;
    }
    cout<<a<<","<<b<<"\n";
    if(t)cout<<"\n";
  }
}
