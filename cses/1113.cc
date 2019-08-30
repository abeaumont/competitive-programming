// https://cses.fi/problemset/task/1113
#include <bits/stdc++.h>

using namespace std;
using vi=vector<int>;
using vvi=vector<vi>;

int main() {
  string s;
  cin>>s;
  int n=s.size();
  vi t;
  vvi a(27);
  for (int i=0;i<n;i++) a[max(0,s[i]-0x60)].push_back(i);
  for (int i=0;i<27;i++) for (int x:a[i]) t.push_back(x);
  int x=s.find('#');
  for (int i=0;i<n-1;i++) cout<<s[x=t[x]];
  cout<<endl;
}
