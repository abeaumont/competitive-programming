// https://codeforces.com/contest/1080/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll n,k;
  cin>>n>>k;
  cout<<(n*2-1)/k+1+(n*5-1)/k+1+(n*8-1)/k+1<<endl;
}
