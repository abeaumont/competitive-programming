// https://www.aceptaelreto.com/problem/statement.php?id=378
#include<bits/stdc++.h>
using namespace std;
using ii=tuple<int,int>;
using vii=vector<ii>;
int main(){
  while(1){
    int n,x,y;
    cin>>n;
    if(!n)break;
    vii a(n);
    for(int i=0;i<n;i++){
      cin>>x>>y;
      a[i]=make_tuple(x,y);
    }
    sort(a.begin(),a.end());
    bool ok=1;
    for(int i=0;i<n-1;i++){
      int u,v;
      tie(u,v)=a[i];
      tie(x,y)=a[i+1];
      if(x>u&&y<=v)ok=0;
    }
    cout<<(ok?"SI\n":"NO\n");
  }
}
