// https://codeforces.com/contest/1151/problem/B
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vvi a(n,vi(m));
  vvi r(n,vi(10));
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>a[i][j];
  for(int k=0;k<10;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        r[i][k]|=((a[i][j]>>k)&1)?2:1;
  for(int k=0;k<10;k++){
    int c=0,d=0;
    for(int i=0;i<n;i++)
      if(r[i][k]==2)c++;
      else if(r[i][k]==3)d++;
    if(c%2){
      vi s;
      for(int i=0;i<n;i++){
        if(r[i][k]<3){
          s.push_back(1);
          continue;
        }
        for(int j=0;j<m;j++)
          if(!((a[i][j]>>k)&1)){
            s.push_back(j+1);
            break;
          }
      }
      cout<<"TAK\n";
      for(int i=0;i<n;i++)cout<<s[i]<<" \n"[i==n-1];
      return 0;
    }else if(d){
      vi s;
      for(int i=0;i<n;i++){
        if(r[i][k]<3){
          s.push_back(1);
          continue;
        }
        if(d){
          d=0;
          for(int j=0;j<m;j++)
            if(((a[i][j]>>k)&1)){
              s.push_back(j+1);
              break;
            }
        }else
          for(int j=0;j<m;j++)
            if(!((a[i][j]>>k)&1)){
              s.push_back(j+1);
              break;
            }
      }
      cout<<"TAK\n";
      for(int i=0;i<n;i++)cout<<s[i]<<" \n"[i==n-1];
      return 0;
    }
  }
  cout<<"NIE\n";
}
