// https://open.kattis.com/problems/kolone
#include<bits/stdc++.h>
using namespace std;
int main(){
  int m,n,t;
  string s1,s2;
  cin>>m>>n>>s1>>s2>>t;
  char r[m+n];
  reverse(s1.begin(),s1.end());
  for(int i=0;i<m;i++){
    int k=t-(m-i)+1;
    if(k<0)k=0;
    if(k>n)k=n;
    r[k+i]=s1[i];
  }
  for(int i=0;i<n;i++){
    int k=t-(n-i)+1;
    if(k<0)k=0;
    if(k>m)k=m;
    r[m+n-k-i-1]=s2[n-i-1];
  }
  for(int i=0;i<m+n;i++)cout<<r[i];
  cout<< endl;
}
