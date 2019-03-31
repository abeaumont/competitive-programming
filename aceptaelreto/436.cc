// https://www.aceptaelreto.com/problem/statement.php?id=436
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a,b;
  while(cin>>a>>b){
    b*=1000000;
    int i=0;
    for(;a<=b;a*=2,i++);
    cout<<i<<endl;
  }
}
