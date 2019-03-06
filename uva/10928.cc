// https://uva.onlinejudge.org/external/109/10928.pdf
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  int t,n,x;
  cin>>t;
  while(t--){
    cin>>n;
    string s;
    getline(cin,s);
    int m=n;
    vi r;
    for(int i=0;i<n;i++){
      getline(cin,s);
      stringstream in(s);
      int k=0;
      while(in>>x)k++;
      if(k<m){
        m=k;
        r=vi(1,i+1);
      }else if(k==m)r.push_back(i+1);
    }
    for(int i=0;i<r.size();i++)cout<<r[i]<<" \n"[i==r.size()-1];
  }
}
