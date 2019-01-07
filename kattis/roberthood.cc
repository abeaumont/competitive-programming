// https://open.kattis.com/problems/roberthood
#include<bits/stdc++.h>
using namespace std;
using p=complex<double>;
using vp=vector<p>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,s;
  cin>>n;
  vp a(n);
  for(int i=0;i<n;i++){
    double x,y;
    cin>>x>>y;
    a[i]={x,y};
  }
  sort(a.begin(),a.end(),[](p a,p b){
    return a.real()<b.real()||(a.real()==b.real()&&a.imag()<b.imag());
  });
  vp b;
  b.push_back(a[0]);
  for(int i=0;i<n;i++)
    if(b.back()!=a[i])b.push_back(a[i]);
  swap(a,b);
  n=a.size();
  vp h;
  for(int i=0;i<min(n,2);i++)h.push_back(a[i]);
  for(int i=2;i<n;i++){
    while((s=h.size())>=2){
      p v2=a[i]-h[s-1],v1=h[s-1]-h[s-2];
      if((conj(v1)*v2).imag()<=0)break;
      h.pop_back();
    }
    h.push_back(a[i]);
  }
  for(int i=n-2;i>=0;i--){
    while((s=h.size())>=2){
      p v2=a[i]-h[s-1],v1=h[s-1]-h[s-2];
      if((conj(v1)*v2).imag()<=0)break;
      h.pop_back();
    }
    h.push_back(a[i]);
  }
  h.pop_back();
  s=h.size();
  double m=0;
  for(int i=0;i<s-1;i++)
    for(int j=i+1;j<s;j++)
      m=max(m,abs(h[i]-h[j]));
  cout<<setprecision(12)<<m<<endl;
}
