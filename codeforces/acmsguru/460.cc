// https://codeforces.com/problemsets/acmsguru/problem/99999/460
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,l;
  cin>>n;
  while(n--){
    string s;
    cin>>s;
    l=s.size();
    if(s[l-1]=='x'||s[l-1]=='s'||s[l-1]=='o'||(s[l-1]=='h'&&s[l-2]=='c'))cout<<s<<"es\n";
    else if(s[l-1]=='f')cout<<s.substr(0,l-1)<<"ves\n";
    else if(s[l-1]=='e'&&s[l-2]=='f')cout<<s.substr(0,l-2)<<"ves\n";
    else if(s[l-1]=='y')cout<<s.substr(0,l-1)<<"ies\n";
    else cout<<s<<"s\n";
  }
}
