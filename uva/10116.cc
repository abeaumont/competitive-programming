// https://uva.onlinejudge.org/external/101/10116.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
using vs=vector<string>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    int n,m,r;
    cin>>n>>m>>r;
    if(!n)break;
    vs a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vvi b(n,vi(m));
    int y=0,x=r-1,k=0;
    while(y>=0&&y<n&&x>=0&&x<m&&!b[y][x]){
      b[y][x]=++k;
      switch(a[y][x]){
      case'N':y--;break;
      case'S':y++;break;
      case'W':x--;break;
      case'E':x++;
      }
    }
    if(y<0||y>=n||x<0||x>=m)cout<<k<<" step(s) to exit\n";
    else cout<<b[y][x]-1<<" step(s) before a loop of "<<k-b[y][x]+1<<" step(s)\n";
  }
}
