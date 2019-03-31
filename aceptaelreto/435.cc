// https://www.aceptaelreto.com/problem/statement.php?id=435
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int main(){
  for(;;){
    string s;
    getline(cin,s);
    if(s.empty())break;
    vi a(10);
    for(char c:s)a[c-'0']++;
    int x=a[0];
    bool o=1;
    for(int y:a)
      if(x!=y)
        o=0;
    if(!o)cout<<"no ";
    cout<<"subnormal\n";
  }
}
