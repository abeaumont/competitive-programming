// https://open.kattis.com/problems/skocimis
#include <bits/stdc++.h>

using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  cout<<max(b-a,c-b)-1<<endl;
}
