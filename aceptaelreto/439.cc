// https://www.aceptaelreto.com/problem/statement.php?id=439
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  while(n--){
    string s,t;
    cin>>s>>t;
    int a=atoi(s.substr(2).c_str()),b=atoi(t.substr(2).c_str());
    if(s[0]=='D'&&t[0]=='T')cout<<"V="<<a/b<<"\n";
    if(s[0]=='D'&&t[0]=='V')cout<<"T="<<a/b<<"\n";
    if(s[0]=='T'&&t[0]=='D')cout<<"V="<<b/a<<"\n";
    if(s[0]=='T'&&t[0]=='V')cout<<"D="<<a*b<<"\n";
    if(s[0]=='V'&&t[0]=='D')cout<<"T="<<b/a<<"\n";
    if(s[0]=='V'&&t[0]=='T')cout<<"D="<<a*b<<"\n";
  }
}
