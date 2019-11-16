// https://codeforces.com/contest/1082/problem/C
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  int n;
  string s;
  int m=0,g=0,z=0,t=0,p=0,x=0;
  cin>>n>>s;
  for(int i=0;i<n;i++)t+=s[i]=='G';
  for(int i=0;i<n;i++){
    if(s[i]=='G')g++;
    else{
      if(z){
        if(t>g)m=max(m,g+1);
        else m=max(m,g);
        g-=z;
        z=g;
      }
      else z=g;
    }
  }
  if(t>g)m=max(m,g+1);
  else m=max(m,g);
  cout<<m<<endl;
}
