// https://open.kattis.com/problems/restaurant
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n;
  while(n){
    int a=0,b=0;
    for(int i=0;i<n;i++){
      string s;
      cin>>s>>m;
      if(s=="DROP"){
        a+=m;
        cout<<"DROP 2 "<<m<<endl;
      }else{
        if(m>b){
          if(b)cout<<"TAKE 1 "<<b<<endl;
          cout<<"MOVE 2->1 "<<a<<endl;
          cout<<"TAKE 1 "<<m-b<<endl;
          b=a+b-m;
          a=0;
        }else{
          cout<<"TAKE 1 "<<m<<endl;
          b-=m;
        }
      }
    }
    cin>>n;
    if(n)cout<<endl;
  }
}
