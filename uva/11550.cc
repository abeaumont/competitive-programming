// https://uva.onlinejudge.org/external/115/11550.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vvi=vector<vi>;
using sii=unordered_set<ii>;
int main(){
  int t,n,m,x;
  cin>>t;
  while(t--){
    cin>>n>>m;
    vvi b(m);
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        cin>>x;
        if(x)b[j].push_back(i);
      }
    int o=1;
    vvi a(n,vi(n));
    for(int i=0;i<m;i++){
      if(b[i].size()!=2||a[b[i][0]][b[i][1]]){
        o=0;
        break;
      }
      a[b[i][0]][b[i][1]]=1;
    }
    cout<<(o?"Yes\n":"No\n");
  }
}
