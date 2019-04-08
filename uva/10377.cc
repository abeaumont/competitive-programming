// https://uva.onlinejudge.org/external/103/10377.pdf
#include<bits/stdc++.h>
using namespace std;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n,m,y,x,o,q;
  int dy[]={-1,0,1,0};
  int dx[]={0,1,0,-1};
  cin>>t;
  for(int T=0;T<t;T++){
    cin>>n>>m;
    string s;
    getline(cin,s);
    vs a(n);
    for(int i=0;i<n;i++){
      getline(cin,s);
      a[i]=s;
    }
    cin>>y>>x;
    getline(cin,s);
    y--;x--;
    o=0;q=0;
    for(;;){
      getline(cin,s);
      for(char c:s){
        if(c=='L')o=!o?3:o-1;
        else if(c=='R')o=o==3?0:o+1;
        else if(c=='F'){
          if(a[y+dy[o]][x+dx[o]]!='*'){y+=dy[o];x+=dx[o];}
        }else if(c=='Q'){q=1;break;}
      }
      if(q)break;
    }
    for(;;){
      getline(cin,s);
      if(s.empty())break;
    }
    if(T)cout<<"\n";
    cout<<y+1<<" "<<x+1<<" "<<"NESW"[o]<<"\n";
  }
}
