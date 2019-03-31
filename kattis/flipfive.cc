// https://open.kattis.com/problems/flipfive
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p;
  cin>>p;
  while(p--){
    vs a(3);
    for(int i=0;i<3;i++)cin>>a[i];
    vector<bitset<3>>b(3);
    for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
        b[i][j]=a[i][j]=='*';
    int M=9;
    function<void(int,int,int)>f=[&](int i,int j,int k){
      if(i==3){
        int z=0;
        for(auto &x:b)z+=x.count();
        if(!z)M=min(M,k);
        return;
      }
      function<void()>t=[&](){
        b[i][j].flip();
        if(i>0)b[i-1][j].flip();
        if(i<2)b[i+1][j].flip();
        if(j>0)b[i][j-1].flip();
        if(j<2)b[i][j+1].flip();
      };
      f(i+(j==2),(j+1)%3,k);
      t();
      f(i+(j==2),(j+1)%3,k+1);
      t();
    };
    f(0,0,0);
    cout<<M<<endl;
  }
}
