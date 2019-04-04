// https://uva.onlinejudge.org/external/8/824.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    int y,x,d,j,k,l;
    cin>>x>>y>>d;
    if(x==-1)break;
    vvi a(3,vi(3));
    for(int i=0;i<8;i++){
      cin>>j>>k>>l;
      a[y-k+1][j-x+1]=l;
    }
    int u[]={-1,-1,0,1,1,1,0,-1};
    int v[]={0,-1,-1,-1,0,1,1,1};
    int e=(d-2)%8;
    if(e<0)e+=8;
    while(!a[1+u[e]][1+v[e]])e=(e+1)%8;
    cout<<e<<"\n";
  }
}
