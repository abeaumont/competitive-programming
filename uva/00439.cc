// https://uva.onlinejudge.org/external/4/439.pdf
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using qii=queue<ii>;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    string s;
    getline(cin,s);
    if(s.empty())break;
    qii q;
    vvi d(8,vi(8)),t(8,vi(8));
    int y=s[0]-'a',x=s[1]-'1';
    q.emplace(y,x);
    t[y][x]=1;
    y=s[3]-'a';x=s[4]-'1';
    while(!t[y][x]){
      int i,j;
      tie(i,j)=q.front();
      q.pop();
      int r[]={-2,-2,-1,-1,1,1,2,2};
      int c[]={-1,1,-2,2,-2,2,-1,1};
      for(int k=0;k<8;k++){
        int u=i+r[k],v=j+c[k];
        if(u>=0&&u<8&&v>=0&&v<8&&!t[u][v]){
          t[u][v]=1;
          d[u][v]=d[i][j]+1;
          q.emplace(u,v);
        }
      }
    }
    cout<<"To get from "<<s.substr(0,2)<<" to "<<s.substr(3,2)
        <<" takes "<<d[y][x]<< " knight moves.\n";
  }
}
