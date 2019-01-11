// https://codeforces.com/problemsets/acmsguru/problem/99999/486
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s1,s2;
  int n=0,m=0;
  cin>>s1>>s2;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      if(s1[i]==s2[j]){
        n+=i==j;
        m+=i!=j;
      }
  cout<<n<<" "<<m<<"\n";
}
