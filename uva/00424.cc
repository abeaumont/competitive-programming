// https://uva.onlinejudge.org/external/4/424.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vvi a;
  while(true){
    string s;
    cin>>s;
    if(s=="0")break;
    vi b(s.size());
    for(int i=0;i<s.size();i++)b[i]=s[i]-'0';
    reverse(b.begin(),b.end());
    a.push_back(b);
  }
  vi r;
  int c=0;
  for(int i=0;i<105;i++){
    for(vi &b:a)
      if(b.size()>i)c+=b[i];
    r.push_back(c%10);
    c/=10;
  }
  while(r.size()>1&&r.back()==0){
    r.pop_back();
  }
  reverse(r.begin(),r.end());
  for(int k:r)cout<<k;
  cout<<endl;
}
