// https://uva.onlinejudge.org/external/6/614.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  for(int t=0;;t++){
    int n,m,a,b,c,d;
    cin>>n>>m>>a>>b>>c>>d;
    if(!n)break;
    a--;b--;c--;d--;
    vvi e(n,vi(m)),f(n,vi(m));
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin>>e[i][j];
    function<bool(int,int,int)>dfs=[&](int i,int j,int k){
      f[i][j]=k;
      if(i==c&&j==d)return 1;
      int y[]={0,-1,0,1};
      int x[]={-1,0,1,0};
      for(int l=0;l<4;l++){
        if(l==0&&(!j||e[i][j-1]&1))continue;
        else if(l==1&&(!i||e[i-1][j]&2))continue;
        else if(l==2&&(e[i][j]&1))continue;
        else if(l==3&&(e[i][j]&2))continue;
        int u=i+y[l],v=j+x[l];
        if(u>=0&&u<n&&v>=0&&v<m&&!f[u][v])
          if(dfs(u,v,k+1))
            return 1;
      }
      f[i][j]=-1;
      return 0;
    };
    dfs(a,b,1);
    printf("Maze %d\n\n",t+1);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
        if(!i||(e[i-1][j]&2))cout<<"+---";
        else cout<<"+   ";
      cout<<"+\n";
      for(int j=0;j<m;j++){
        if(!j||e[i][j-1]&1)cout<<"|";
        else cout<<" ";
        if(f[i][j]>0)printf("% 3d",f[i][j]);
        else if(f[i][j]<0)printf("???");
        else printf("   ");
      }
      cout<<"|\n";
    }
    for(int j=0;j<m;j++)cout<<"+---";
    cout<<"+\n\n\n";
  }
}
