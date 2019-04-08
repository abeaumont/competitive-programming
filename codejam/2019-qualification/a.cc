// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  for(int T=1;T<=t;T++){
    string s;
    cin>>s;
    int n=s.size();
    vi a(n),b(n);
    for(int i=0;i<n;i++){
      a[i]=s[n-i-1]-'0';
      if(a[i]==4){
        a[i]--;
        b[i]=1;
      }
    }
    while(!b.back())b.pop_back();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    cout<<"Case #"<<T<<": ";
    for(int x:a)cout<<x;
    cout<<" ";
    for(int x:b)cout<<x;
    cout<<"\n";
  }
}
