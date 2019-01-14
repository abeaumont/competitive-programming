// https://open.kattis.com/problems/dejavu
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
using ll=long long;
const int N=100000;
ll X[N+1],Y[N+1];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n,x,y;
  cin>>n;
  vii a(n);
  for(int i=0;i<n;i++){
    cin>>x>>y;
    a[i]={x,y};
    X[x]++;
    Y[y]++;
  }
  ll c=0;
  for(ii p:a){
    tie(x,y)=p;
    c+=(Y[y]-1)*(X[x]-1);
  }
  cout<<c<<"\n";
}
