// https://open.kattis.com/problems/moviecollection
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using vi=vector<int>;
using si=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t,n,r,x,y;
  cin>>t;
  while(t--){
    cin>>n>>r;
    vi a(n);
    si b;
    for(int i=0;i<n;i++){
      a[i]=i;
      b.insert(i);
    }
    for(int i=0;i<r;i++){
      cin>>x;x--;
      y=a[x];
      cout<<b.order_of_key(y)<<" \n"[i==r-1];
      b.erase(y);
      a[x]=-(i+1);
      b.insert(-(i+1));
    }
  }
}
