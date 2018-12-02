// https://open.kattis.com/problems/equalsumseasy
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using si=set<int>;
int main(){
  int T,n;
  cin>>T;
  for(int t=1;t<=T;t++){
    cin>>n;
    vi a(n),b(n);
    for (int i=0;i<n;i++)cin>>a[i];
    si s;
    int c=1000000000;
    function<void(int,int)>f=[&](int i, int k){
      if(i==n){
        if(k>0){
          if(s.count(k))c=min(c,k);
          else s.insert(k);
        }
      }else{
        f(i+1,k);
        f(i+1,k+a[i]);
      }
    };
    f(0,0);
    cout<<"Case #"<<t<<":\n";
    if(c){
      int l=0;
      vi d;
      function<void(int,int)>f=[&](int i, int k){
        if(i==n){
          if(k==c&&l++<2)
            for(int i=0;i<d.size();i++)cout<<d[i]<<" \n"[i==d.size()-1];
        }else{
          f(i+1,k);
          d.push_back(a[i]);
          f(i+1,k+a[i]);
          d.pop_back();
        }
      };
      f(0,0);
    }else cout<<"Impossible\n";
  }
}
