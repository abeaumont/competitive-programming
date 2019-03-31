// https://www.aceptaelreto.com/problem/statement.php?id=443
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  for(;;){
    int n;
    cin>>n;
    if(!n)break;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vi b(a);
    sort(b.begin(),b.end());
    int c=0;
    int i=0,j=0;
    for(int i=0,j=0;i<n;i++)
      if(a[i]==b[j])j++;
      else c++;
    cout<<c<<"\n";
  }
}
