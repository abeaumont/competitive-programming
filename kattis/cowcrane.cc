// https://open.kattis.com/problems/cowcrane
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll m,l,M,L,tm,tl,d1,d2;
  cin>>m>>l>>M>>L>>tm>>tl;
  bool p=false;
  d1=llabs(m)+llabs(l-m)+llabs(L-l);
  d2=llabs(l-L)+llabs(M-l);
  if(d1<=tl&&d1+d2<=tm)p=true;
  d1=llabs(m)+llabs(M-m);
  d2=llabs(l-M)+llabs(L-l);
  if(d1<=tm&&d1+d2<=tl)p=true;
  d1=llabs(l)+llabs(m-l)+llabs(M-m);
  d2=llabs(m-M)+llabs(L-m);
  if(d1<=tm&&d1+d2<=tl)p=true;
  d1=llabs(l)+llabs(L-l);
  d2=llabs(m-L)+llabs(M-m);
  if(d1<=tl&&d1+d2<=tm)p=true;
  if(!p)cout<<"im";
  cout<<"possible\n";
}
