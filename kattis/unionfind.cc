// https://open.kattis.com/problems/unionfind
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
  int n,q,a,b;
  char c;
  cin>>n>>q;
  vi p(n);
  for(int i=0;i<n;i++)p[i]=i;
  function<int(int)> find=[&](int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
  };
  auto join=[&](int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    p[y]=x;
  };
  for(int i=0;i<q;i++){
    cin>>c>>a>>b;
    if(c=='=')join(a,b);
    else cout<<(find(a)==find(b)?"yes\n":"no\n");
  }
}
