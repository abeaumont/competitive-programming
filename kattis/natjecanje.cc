// https://open.kattis.com/problems/natjecanje
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int n,s,r;
  cin>>n>>s>>r;
  vi a(s),b(r);
  for(int i=0;i<s;i++)cin>>a[i];
  for(int i=0;i<r;i++)cin>>b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int i=0,j=0,c=0;
  while(i<s&&j<r){
    if(b[j]<a[i]-1)j++;
    else if(b[j]>a[i]+1)i++;
    else if(b[j]>=a[i]||j==r-1||b[j+1]>a[i]){
      c++; j++; i++;
    }else j++;
  }
  cout<<s-c<<endl;
}
