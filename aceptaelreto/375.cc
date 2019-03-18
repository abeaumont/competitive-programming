// https://www.aceptaelreto.com/problem/statement.php?id=375
#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  while(cin>>s){
    int c;
    c=(s[0]-'0')*10+s[1]-'0';
    c=(c+17)%36+1;
    string t;
    if(s.size()==3){
      if(s[2]=='R')t="L";
      else if(s[2]=='L')t="R";
      else t="C";
    }
    printf("%02d%s\n",c,t.c_str());
  }
}
