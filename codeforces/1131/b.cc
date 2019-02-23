// https://codeforces.com/contest/1131/problem/B
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a=0,b=0,c,d,s=1;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>c>>d;
    int k=min(c,d)-max(a,b);
    if(k>=0&&a!=b)k++;
    s+=max(0,k);
    a=c;b=d;
  }
  cout<<s<<"\n";
}
