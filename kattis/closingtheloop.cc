// https://open.kattis.com/problems/closingtheloop
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int t,n,l;
  cin>>t;
  for(int T=1;T<=t;T++){
    cin>>n;
    vi a,b;
    for(int i=0;i<n;i++){
      string s;
      cin>>s;
      stringstream in(s.substr(0,s.size()-1));
      in>>l;
      if(s[s.size()-1]=='B')a.push_back(l);
      else b.push_back(l);
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    int r=0,k=min(a.size(),b.size());
    if(k){
      for(int i=0;i<k;i++)r+=a[i]+b[i];
      r-=k*2;
    }
    printf("Case #%d: %d\n",T,r);
  }
}
