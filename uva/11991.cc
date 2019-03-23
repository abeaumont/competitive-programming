// https://uva.onlinejudge.org/external/119/11991.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using mvi=unordered_map<int,vi>;
int main(){
  int n,m,k,v;
  while(cin>>n>>m){
    mvi a;
    for(int i=1;i<=n;i++){
      cin>>v;
      a[v].push_back(i);
    }
    for(int i=0;i<m;i++){
      cin>>k>>v;
      cout<<(a[v].size()>=k?a[v][k-1]:0)<<"\n";
    }
  }
}
