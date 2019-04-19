// https://codeforces.com/contest/1151/problem/A
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  char x;
  cin>>n;
  vvi a(n,vi(4));
  for(int i=0;i<n;i++){
    cin>>x;
    int y=abs(x-'A');
    a[i][0]=min(y,26-y);
    y=abs(x-'C');
    a[i][1]=min(y,26-y);
    y=abs(x-'T');
    a[i][2]=min(y,26-y);
    y=abs(x-'G');
    a[i][3]=min(y,26-y);
  }
  int c=0;
  for(int j=0;j<4;j++)c+=a[j][j];
  for(int i=1;i<=n-4;i++){
    int k=0;
    for(int j=0;j<4;j++)k+=a[i+j][j];
    c=min(c,k);
  }
  cout<<c<<"\n";
}
