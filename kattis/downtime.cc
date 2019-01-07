// https://open.kattis.com/problems/downtime
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,k,x,m=0;
  priority_queue<ii,vector<ii>,greater<ii>> q;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>x;
    q.push({x,1});
    q.push({x+1000,-1});
  }
  x=0;
  while(!q.empty()){
    x+=get<1>(q.top());
    q.pop();
    m=max(m,x);
  }
  cout<<(m-1)/k+1<<endl;
}
