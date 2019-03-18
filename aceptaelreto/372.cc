// https://www.aceptaelreto.com/problem/statement.php?id=372
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    int k=(s[0]<='Z')*32;
    s[0]+=k;
    reverse(s.begin(),s.end());
    s[0]-=k;
    cout<<s<<"\n";
  }
}
