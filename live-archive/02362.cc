// https://icpcarchive.ecs.baylor.edu/external/23/p2362.pdf
#include<bits/stdc++.h>
using namespace std;
int main(){
  double x,s=0;
  for(int i=0;i<12;i++){
    cin>>x;
    s+=x;
  }
  cout<<fixed<<setprecision(2)<<'$'<<s/12<<endl;
}
