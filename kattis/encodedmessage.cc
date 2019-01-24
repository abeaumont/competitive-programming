// https://open.kattis.com/problems/encodedmessage
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  while(n--){
    string s;
    cin>>s;
    int k=1;
    for(;k<=s.size();k++)
      if(k*k==s.size())break;
    for(int j=k-1;j>=0;j--)
      for(int i=0;i<k;i++)
        cout<<s[k*i+j];
    cout<<"\n";
  }
}

