// https://uva.onlinejudge.org/external/108/10895.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vi=vector<int>;
using vii=vector<ii>;
using vvii=vector<vii>;
int main(){
  int n,m,c,x;
  while(cin>>n>>m){
    vvii a(m);
    for(int i=0;i<n;i++){
      cin>>c;
      vi b(c);
      for(int j=0;j<c;j++)cin>>b[j];
      for(int j=0;j<c;j++){
        cin>>x;
        a[b[j]-1].push_back({i, x});
      }
    }
    cout<<m<<" "<<n<<"\n";
    for(int i=0;i<m;i++){
      sort(a[i].begin(),a[i].end());
      c=a[i].size();
      cout<<c;
      for(int j=0;j<c;j++)cout<<" "<<get<0>(a[i][j])+1;
      cout<<"\n";
      if(c>0)for(int j=0;j<c;j++)cout<<get<1>(a[i][j])<<" \n"[j==c-1];
      else cout<<"\n";
    }
  }
}
