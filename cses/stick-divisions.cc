// https://cses.fi/problemset/task/1161
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using pq=priority_queue<ll,vector<ll>,greater<ll>>;

int main() {
  ll x,n;
  cin>>x>>n;
  pq q;
  for (int i=0; i<n; i++) {
    cin>>x;
    q.push(x);
  }
  ll s=0;
  while (q.size()>1) {
    ll k=q.top();q.pop();
    k+=q.top();q.pop();
    s+=k;
    q.push(k);
  }
  cout<<s<<endl;
}
