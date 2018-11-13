// https://open.kattis.com/problems/acm2
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int n,p,b,c;
  cin>>n>>p;
  vi a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  if(a[p]>300){
    cout<<"0 0\n";
    return 0;
  }
  b=c=a[p];
  swap(a[p],a[n-1]);
  a.pop_back();
  sort(a.begin(),a.end());
  int i=0;
  for(;i<n-1&&b+a[i]<=300;i++){
    b+=a[i];
    c+=b;
  }
  cout<<i+1<<" "<<c<<endl;
}
