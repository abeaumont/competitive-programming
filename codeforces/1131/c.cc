// https://codeforces.com/contest/1131/problem/C
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
int main(){
  int n;
  cin>>n;
  vi a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(), a.end());
  for(int i=0;i<n;i+=2)cout<<a[i]<<" ";
  for(int i=n-1-(n%2);i>=1;i-=2)cout<<a[i]<<" \n"[i==1];
}
