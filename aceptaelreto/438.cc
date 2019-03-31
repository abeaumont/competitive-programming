// https://www.aceptaelreto.com/problem/statement.php?id=438
#include<bits/stdc++.h>
using namespace std;
int main(){
  for(;;){
    string s;
    getline(cin,s);
    if(s.empty())break;
    int a=0,b=0;
    for(char c:s){
      if(c=='!')a++;
      else if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))b++;
    }
    if(a>b)cout<<"ESGRITO\n";
    else cout<<"escrito\n";
  }
}
