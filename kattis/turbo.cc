// https://open.kattis.com/problems/turbo
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using vi=vector<int>;
using si=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,x;
  cin>>n;
  vi a(n);
  si b;
  for(int i=0;i<n;i++){
    cin>>x;x--;
    a[x]=i;
    b.insert(i);
  }
  for(int i=0;i<=(n-1)/2;i++){
    cout<<b.order_of_key(a[i])<<endl;
    b.erase(a[i]);
    if(i==n-i-1)break;
    cout<<b.size()-b.order_of_key(a[n-i-1])-1<<endl;
    b.erase(a[n-i-1]);
  }
}
