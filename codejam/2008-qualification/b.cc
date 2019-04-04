// https://code.google.com/codejam/contest/32013/dashboard#s=p1
#include<bits/stdc++.h>
using namespace std;
using iib=tuple<int,int,bool>;
using viib=vector<iib>;
using pq=priority_queue<int,vector<int>,greater<int>>;
int main(){
  int n,na,nb,t,a,b,c,d;
  cin>>n;
  for(int T=1;T<=n;T++){
    cin>>t>>na>>nb;
    viib x(na+nb);
    for(int i=0;i<na;i++){
      scanf("%d:%d %d:%d\n",&a,&b,&c,&d);
      x[i]={a*60+b,c*60+d,1};
    }
    for(int i=0;i<nb;i++){
      scanf("%d:%d %d:%d\n",&a,&b,&c,&d);
      x[na+i]={a*60+b,c*60+d,0};
    }
    sort(x.begin(),x.end());
    pq qa,qb;
    int k=0,l=0;
    for(iib z:x){
      tie(a,b,c)=z;
      if(c){
        if(qa.empty()||qa.top()>a)k++;
        else qa.pop();
        qb.push(b+t);
      }else{
        if(qb.empty()||qb.top()>a)l++;
        else qb.pop();
        qa.push(b+t);
      }
    }
    printf("Case #%d: %d %d\n",T,k,l);
  }
}
