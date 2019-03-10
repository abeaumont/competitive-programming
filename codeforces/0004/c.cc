// https://codeforces.com/contest/4/problem/C
#include <bits/stdc++.h>
using namespace std;
using ss=unordered_set<string>;
using msi=unordered_map<string,int>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ss s;
  msi m;
  cin>>n;
  for(int i=0;i<n;i++){
    string x;
    cin>>x;
    stringstream ss;
    if(s.count(x)){
      int j=m[x];
      while(true){
        ss<<x<<j;
        if(!s.count(ss.str()))break;
        j++;
      }
      m[x]=j+1;
      s.insert(ss.str());
      cout<<ss.str()<<endl;
    }else{
      cout<<"OK\n";
      s.insert(x);
      m[x]=max(m[x],1);
    }
  }
}
