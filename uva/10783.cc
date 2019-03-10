// https://uva.onlinejudge.org/external/107/10783.pdf
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t,a,b;
  cin>>t;
  for(int i=1;i<=t;i++){
    cin>>a>>b;
    int s=0;
    for(int j=a;j<=b;j++)
      if(j%2)s+=j;
    cout<<"Case "<<i<<": "<<s<<"\n";
  }
}
