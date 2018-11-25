// https://open.kattis.com/problems/deduplicatingfiles
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vs=vector<string>;
int main(){
  int n;
  cin>>n;
  while(n){
    string s;
    getline(cin,s);
    vi a(n);
    vs b(n);
    int k=0,l=n;
    for(int i=0;i<n;i++){
      getline(cin,b[i]);
      int x=0;
      for(char c:b[i])x^=c;
      a[i]=x;
    }
    for(int i=0;i<n-1;i++){
      bool ok=true;
      for(int j=i+1;j<n;j++){
        if(a[i]!=a[j])continue;
        if(b[i]==b[j])ok=false;
        else k++;
      }
      if(!ok)l--;
    }
    cout<<l<<" "<<k<<endl;
    cin>>n;
  }
}
