// https://www.aceptaelreto.com/problem/statement.php?id=377
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  while(getline(cin,s)){
    if(s.empty())break;
    int n=0;
    for(char x:s){
      n=(n*10)+x-'0';
      n%=16;
    }
    cout<<((n&0xf)==0||(n&0xf)==1||(n&0xf)==4||(n&0xf)==9?"NO SE\n":"IMPERFECTO\n");
  }
}
