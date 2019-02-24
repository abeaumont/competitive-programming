// https://codeforces.com/contest/1130/problem/A
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,a=0,b=0,c=0;
  cin>>n;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    if (x==0)a++;
    else if(x>0)b++;
    else c++;
  }
  int h=(n-1)/2+1;
  if(b>=h)cout<<"1\n";
  else if(c>=h)cout<<"-1\n";
  else cout<<"0\n";
}
