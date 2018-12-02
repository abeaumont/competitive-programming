// https://open.kattis.com/problems/lastfactorialdigit
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    if(n>=5)cout<<0<<endl;
    else if(n==3)cout<<6<<endl;
    else cout<<n<<endl;
  }
}
