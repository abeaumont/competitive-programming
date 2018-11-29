// https://open.kattis.com/problems/qaly
#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  double q,y,t=0;
  for(int i=0;i<n;i++){
    cin>>q>>y;
    t+=q*y;
  }
  cout<<t<<endl;
}
