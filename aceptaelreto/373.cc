// https://www.aceptaelreto.com/problem/statement.php?id=373
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n,k;
  cin>>n;
  for(ll i=0;i<n;i++){
    cin>>k;
    cout<<k*k*k-(k-2)*(k-2)*(k-2)<<"\n";
  }
}
