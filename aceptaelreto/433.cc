// https://www.aceptaelreto.com/problem/statement.php?id=433
#include<bits/stdc++.h>
using namespace std;
int main(){
  for(;;){
    int n;
    cin>>n;
    if(!n)break;
    for(int i=0;;i++)
      if(i*(i+1)/2>=n){
        cout<<i<<"\n";
        break;
      }
  }
}
