// https://uva.onlinejudge.org/external/119/11966.pdf
#include<bits/stdc++.h>
using namespace std;
using p=complex<double>;
using vp=vector<p>;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n;
  double d,x,y;
  cin>>t;
  for(int T=1;T<=t;T++){
    cin>>n>>d;
    vp a(n);
    for(int i=0;i<n;i++){
      cin>>x>>y;
      a[i]={x,y};
    }
    vvi g(n);
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        if(abs(a[i]-a[j])<=d){
          g[i].push_back(j);
          g[j].push_back(i);
        }
    vi s(n);
    function<void(int)>dfs=[&](int u){
      s[u]=1;
      for(int v:g[u])
        if(!s[v])
          dfs(v);
    };
    int k=0;
    for(int i=0;i<n;i++)
      if(!s[i]){
        k++;
        dfs(i);
      }
    cout<<"Case "<<T<<": "<<k<<"\n";
  }
}
