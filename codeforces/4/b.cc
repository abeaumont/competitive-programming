// https://codeforces.com/contest/4/problem/B
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int d,s,s1=0,s2=0;
  cin>>d>>s;
  vi t1(d),t2(d);
  for(int i=0;i<d;i++)cin>>t1[i]>>t2[i];
  for(int i=0;i<d;i++)s1+=t1[i];
  for(int i=0;i<d;i++)s2+=t2[i];
  if(s<s1||s>s2){
    cout<<"NO\n";
    return 0;
  }
  int e=s-s1;
  cout<<"YES\n";
  for(int i=0;i<d;i++){
    int k=t1[i];
    k=min(k+e,t2[i]);
    e-=(k-t1[i]);
    cout<<k<<" \n"[i==d-1];
  }
}
