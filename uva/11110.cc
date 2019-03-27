// https://uva.onlinejudge.org/external/111/11110.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  for(;;){
    int n,y,x;
    cin>>n;
    if(!n)break;
    vvi a(n,vi(n,n)),s(n,vi(n));
    string t;
    getline(cin,t);
    for(int i=0;i<n-1;i++){
      getline(cin,t);
      stringstream in(t);
      int j=0;
      for(;in>>y>>x;j++){
        y--;x--;
        a[y][x]=i+1;
      }
    }
    function<void(int,int,int)>dfs=[&](int y,int x,int k){
      s[y][x]=k;
      int i[]={-1,0,0,1};
      int j[]={0,-1,1,0};
      for(int l=0;l<4;l++){
        int u=y+i[l],v=x+j[l];
        if(u>=0&&u<n&&v>=0&&v<n&&!s[u][v]&&(a[u][v]==a[y][x]))
          dfs(u,v,k);
      }
    };
    int k=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(!s[i][j])
          dfs(i,j,++k);
    vi c(k+1);
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        c[s[i][j]]++;
    bool o=k==n;
    for(int i=1;i<k;i++)
      if(c[i]!=n)o=0;
    cout<<(o?"good\n":"wrong\n");
  }
}
