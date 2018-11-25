// https://open.kattis.com/problems/grandpabernie
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using msvi=unordered_map<string,vi>;
int main(){
  int n,q,y;
  string s;
  msvi m;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s>>y;
    m[s].push_back(y);
  }
  for (auto it=m.begin();it!=m.end();it++)
    sort(it->second.begin(), it->second.end());
  cin>>q;
  while(q--){
    cin>>s>>y;
    cout<<m[s][y-1]<<endl;;
  }
}
