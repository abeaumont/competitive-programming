// https://open.kattis.com/problems/friday
#include <bits/stdc++.h>

using namespace std;
using vi=vector<int>;
int main(){
  int t,d,m;
  cin>>t;
  while(t--){
    cin>>d>>m;
    vi a(m);
    int c=0,s=0;
    for(int i=0;i<m;i++)cin>>a[i];
    for(int i=0;i<m;i++){
      if(a[i]>=13&&(s+13)%7==6)c++;
      s+=a[i];
    }
    cout<<c<<endl;
  }
}
