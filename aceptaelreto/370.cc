// https://www.aceptaelreto.com/problem/statement.php?id=370
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a,b,c,d;
  cin>>n;
  for(int i=0;i<n;i++){
    scanf("%d-%d\n",&a,&b);
    c=min(a,b);
    d=max(a,b);
    if(c%2==0&&d==c+1)cout<<"SI\n";
    else cout<<"NO\n";
  }
}
