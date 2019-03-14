// https://open.kattis.com/problems/bing
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  int n,z=1;
  cin>>n;
  vvi t(n*32, vi(27));
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    int k=0;
    for(char c:s){
      t[k][26]++;
      if(!t[k][c-'a'])
        t[k][c-'a']=z++;
      k=t[k][c-'a'];
    }
    cout<<t[k][26]<<endl;
    t[k][26]++;
  }
}
