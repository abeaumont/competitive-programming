// https://codeforces.com/contest/1056/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
int c[101];
int main(){
  int n,r,x;
  cin>>n;
  vi a;
  for(int i=0;i<n;i++){
    cin>>r;
    for(int j=0;j<r;j++){
      cin>>x;
      c[x]++;
    }
  }
  int m=0;
  for(int i=0;i<=100;i++)m=max(m,c[i]);
  for(int i=0;i<=100;i++)
    if(c[i]==m)a.push_back(i);
  for(int i=0;i<a.size();i++)cout<<a[i]<<" \n"[i==a.size()-1];
}
