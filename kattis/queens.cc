// https://open.kattis.com/problems/queens
#include <bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
int main(){
  int n,y,x,i=0;
  cin>>n;
  vb r(n),c(n),d(2*n),d2(2*n);
  for(;i<n;i++){
    cin>>x>>y;
    if(r[y]||c[x]||d[y+x]||d2[y-x+n])break;
    r[y]=c[x]=d[y+x]=d2[y-x+n]=true;
  }
  cout<<(i==n?"CORRECT\n":"INCORRECT\n");
}
