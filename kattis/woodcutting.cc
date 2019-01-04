// https://open.kattis.com/problems/woodcutting
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n,x,w;
  cin>>t;
  while(t--){
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++){
      cin>>w;
      for(int j=0;j<w;j++){
        cin>>x;
        a[i]+=x;
      }
    }
    sort(a.begin(),a.end());
    int s=0;
    double c=0;
    for(int x:a){
      s+=x;
      c+=s;
    }
    cout<<fixed<<setprecision(10)<<c/a.size()<<endl;
  }
}
