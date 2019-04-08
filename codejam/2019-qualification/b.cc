// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n;
  string s;
  cin>>t;
  for(int T=1;T<=t;T++){
    cin>>n>>s;
    string r(s.size(),'X');
    for(int i=0;i<s.size();i++)r[i]=s[i]=='E'?'S':'E';
    cout<<"Case #"<<T<<": "<<r<<"\n";
  }
}
