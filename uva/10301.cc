// https://uva.onlinejudge.org/external/103/10301.pdf
#include<bits/stdc++.h>
using namespace std;
using pt=complex<double>;
using ptd=tuple<pt,double>;
using vptd=vector<ptd>;
using vi=vector<int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for(;;){
    int n,u,v;
    cin>>n;
    if(n==-1)break;
    vi s=vi(n, 1),p=vi(n);
    for(int i=0;i<n;i++)p[i]=i;
    function<int(int)>find=[&](int i){
      if(i==p[i])return i;
      return p[i]=find(p[i]);
    };
    function<void(int,int)>unite=[&](int i, int j){
      i=find(i);
      j=find(j);
      if(i==j)return;
      if(s[i]<s[j])swap(i,j);
      s[i]+=s[j];
      p[j]=i;
    };
    vptd a(n);
    for(int i=0;i<n;i++){
      double x,y,r;
      cin>>x>>y>>r;
      a[i]={{x,y},r};
    }
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
        pt x,y;
        double r,t;
        tie(x,r)=a[i];
        tie(y,t)=a[j];
        if(r<t){
          swap(r,t);
          swap(x,y);
        }
        if(fabs(y-x)<r+t&&fabs(y-x)+t>r)
          unite(i,j);
      }
    int m=0;
    for(int i=0;i<n;i++)m=max(m,s[i]);
    cout<<"The largest component contains "<<m<<" ring"<<(m!=1?"s":"")<<".\n";
  }
}
