// https://open.kattis.com/problems/kutevi
#include<bits/stdc++.h>
using namespace std;
int a[360];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k,x,d=360;
  cin>>n>>k;
  while(n--){
    cin>>x;
    d = __gcd(x, d);
  }
  while(k--){
    cin>>x;
    cout<<(x%d?"NO\n":"YES\n");
  }
}
