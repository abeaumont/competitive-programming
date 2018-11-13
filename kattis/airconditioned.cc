// https://open.kattis.com/problems/airconditioned
#include <bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
int main(){
  int n,l,u;
  cin>>n;
  vii a(n);
  for(int i=0;i<n;i++){
    cin>>l>>u;
    a[i]={u,l};
  }
  sort(a.begin(),a.end());
  int k=1,t=get<0>(a[0]);
  for(int i=0;i<n;i++){
    tie(u,l)=a[i];
    if(l>t){
      t=u;
      k++;
    }
  }
  cout<<k<<endl;
}
