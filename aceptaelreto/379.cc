// https://www.aceptaelreto.com/problem/statement.php?id=379
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  while(1){
    int n,x,y;
    cin>>n;
    if(!n)break;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    bool d=0;
    int i=n-1;
    for(;i>0;i--)
      if(a[i]==a[i-1])
        break;
    a[i]++;
    for(int j=i+1;j<n;j++)a[j]=a[j-1];
    for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i==n-1];
  }
}
