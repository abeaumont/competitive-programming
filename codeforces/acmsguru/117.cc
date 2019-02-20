// https://codeforces.com/problemsets/acmsguru/problem/99999/117
#include<bits/stdc++.h>
using namespace std;
using vb=vector<bool>;
using vi=vector<int>;
int P=10001;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  vb p(P, true);
  for(int i=2;i<P;i++)
    if(p[i])
      for(int j=2*i;j<P;j+=i) p[j]=false;
  int n,m,k,q=1;
  cin>>n>>m>>k;
  for(int i=2;i<P;i++)
    if(p[i]){
      int c=0;
      while(!(k%i)){
        c++;
        k/=i;
      }
      if(c)q*=((c-1)/m+1)*i;
    }
  int x,c=0;
  for(int i=0;i<n;i++){
    cin>>x;
    if(!(x%q))c++;
  }
  cout<<c<<"\n";
}
