// https://www.aceptaelreto.com/problem/statement.php?id=368
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(1){
    int h,c;
    cin>>h>>c;
    if(!h)break;
    cout<<((h-1)/c+1)*10<<"\n";
  }
}
