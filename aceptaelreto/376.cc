// https://www.aceptaelreto.com/problem/statement.php?id=376
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  while(true){
    int n;
    cin>>n;
    if(!n)break;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int c=0;
    for(int i=1;i<n-1;i++)
      if(a[i]>a[i-1]&&a[i]>a[i+1])
        c++;
    if(a[0]>a[1]&&a[0]>a[n-1])c++;
    if(a[n-1]>a[0]&&a[n-1]>a[n-2])c++;
    cout<<c<<endl;
  }
}
