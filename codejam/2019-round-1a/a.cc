// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104e03
// Only for Test set 1
#include<bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
using vvb=vector<vb>;
using ii=tuple<int,int>;
using vii=vector<ii>;
int main(){
  int t,r,c;
  cin>>t;
  for(int T=1;T<=t;T++){
    cin>>r>>c;
    vii p;
    vvb s(r,vb(c));
    function<bool(int,int,int)>f=[&](int y,int x, int k){
      if(k==r*c)return 1;
      for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
          if(i!=y&&j!=x&&i+j!=y+x&&i-j!=y-x&&!s[i][j]){
            s[i][j]=1;
            p.emplace_back(i,j);
            if(f(i,j,k+1)) return 1;
            p.pop_back();
            s[i][j]=0;
          }
      return 0;
    };
    if(f(0,r*100,0)){
      printf("Case #%d: POSSIBLE\n",T);
      for (ii z:p){
        tie(r,c)=z;
        cout<<r+1<<" "<<c+1<<"\n";
      }
    }else printf("Case #%d: IMPOSSIBLE\n",T);
  }
}
