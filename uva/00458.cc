// https://uva.onlinejudge.org/external/4/458.pdf
#include<bits/stdc++.h>
using namespace std;
int main(){
  for(string s;getline(cin, s);){
    for(int c:s)cout<<char(c-7);
    cout<<"\n";
  }
}
