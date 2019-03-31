// https://www.aceptaelreto.com/problem/statement.php?id=440
#include<bits/stdc++.h>
using namespace std;
int main(){
  for(;;){
    int n;
    cin>>n;
    if(!n)break;
    int m=n,M=0,g=0,c=1,k,x;
    cin>>k;
    for(int i=1;i<n;i++){
      cin>>x;
      if(x<k){
        k=x;
        m=min(m,c);
        M=max(M,c);
        c=1;
        g++;
      }else c++;
    }
    m=min(m,c);
    M=max(M,c);
    g++;
    cout<<g<<" "<<m<<" "<<M<<"\n";
  }
}
