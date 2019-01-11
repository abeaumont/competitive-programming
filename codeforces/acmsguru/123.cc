// https://codeforces.com/problemsets/acmsguru/problem/99999/123
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int k,t,a=1,b=1,s=0;
  cin>>k;
  for(int i=0;i<k;i++){
    s+=a;
    t=a+b;
    a=b;
    b=t;
  }
  cout<<s<<"\n";
}
