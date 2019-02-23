// https://uva.onlinejudge.org/external/1/118.pdf
#include<bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
using vvb=vector<vb>;
int main(){
  int X,Y,x,y;
  char o;
  string s;
  cin>>X>>Y;
  vvb a(X+1, vb(Y+1));
  while(cin>>x>>y>>o>>s){
    bool l=0;
    for(auto c:s){
      if(c=='R'){
        if(o=='N')o='E';
        else if(o=='E')o='S';
        else if(o=='S')o='W';
        else o='N';
      }else if(c=='L'){
        if(o=='N')o='W';
        else if(o=='E')o='N';
        else if(o=='S')o='E';
        else o='S';
      }else{
        if(o=='N'){
          if(y==Y){
            if(!a[x][y]){
              a[x][y]=1;
              l=1;
              break;
            }
          }else y++;
        }else if(o=='E'){
          if(x==X){
            if(!a[x][y]){
              a[x][y]=1;
              l=1;
              break;
            }
          }else x++;
        }else if(o=='S'){
          if(y==0){
            if(!a[x][y]){
              l=1;
              break;
            }
          }else y--;
        }else{
          if(x==0){
            if(!a[x][y]){
              l=1;
              break;
            }
          }else x--;
        }
      }
    }
    printf("%d %d %c%s\n",x,y,o,l?" LOST":"");
  }
}
