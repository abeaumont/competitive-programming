// https://code.google.com/codejam/contest/32013/dashboard
#include<bits/stdc++.h>
using namespace std;
using ss=unordered_set<string>;
int main(){
  int n,s,q;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>s;
    string t;
    getline(cin,t);
    ss x;
    for(int j=0;j<s;j++){
      getline(cin,t);
      x.insert(t);
    }
    cin>>q;
    getline(cin,t);
    ss y;
    string z;
    int c=0;
    for(int j=0;j<q;j++){
      getline(cin,t);
      if(t!=z)y.insert(t);
      if((z.empty()&&y.size()==x.size())||(!z.empty()&&y.size()+1==x.size())){
        c++;
        y.clear();
        z=t;
      }
    }
    cout<<"Case #"<<i<<": "<<c<<"\n";
  }
}
