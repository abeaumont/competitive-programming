// https://uva.onlinejudge.org/external/103/10369.pdf
#include<bits/stdc++.h>
using namespace std;
using pt=complex<double>;
using dii=tuple<double,int,int>;
using vi=vector<int>;
using vp=vector<pt>;
using vdii=vector<dii>;
int main(){
  int t,z,n;
  cin>>t;
  cout<<fixed<<setprecision(2);
  while(t--){
    cin>>z>>n;
    vp a(n);
    for(int i=0;i<n;i++){
      double x,y;
      cin>>x>>y;
      a[i]={x,y};
    }
    if(z>=n){
      cout<<"0\n";
      continue;
    }
    vdii b;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        b.emplace_back(fabs(a[i]-a[j]),i,j);
    sort(b.begin(),b.end());
    vi s=vi(n,1),p=vi(n);
    for(int i=0;i<n;i++)p[i]=i;
    function<int(int)>find=[&](int i){
      if(i==p[i])return i;
      return p[i]=find(p[i]);
    };
    function<void(int,int)>unite=[&](int i,int j){
      i=find(i);
      j=find(j);
      if(i==j)return;
      if(s[i]<s[j])swap(i,j);
      s[i]+=s[j];
      p[j]=i;
    };
    int k=0;
    for(dii x:b){
      double d;
      int i,j;
      tie(d,i,j)=x;
      if(find(i)==find(j))continue;
      unite(i,j);
      k++;
      if(k==n-z){
        cout<<d<<"\n";
        break;
      }
    }
  }
}
