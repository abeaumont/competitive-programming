// https://codeforces.com/contest/1020/problem/B
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  int n;
  cin>>n;
  vi p(n),s(n),a(n,-1);
  for(int i=0;i<n;i++){
    cin>>p[i];
    p[i]--;
  }
  int k=-1;
  function<void(int)> dfs=[&](int i){
    if(s[i]){
      if(a[i]==-1){
        a[i]=i;
        k=i;
      }
      return;
    }
    s[i]=1;
    dfs(p[i]);
    if(k==i)k=-1;
    else if(k!=-1)a[i]=i;
    else if(a[p[i]]!=-1)a[i]=a[p[i]];
  };
  for(int i=0;i<n;i++)
    if(!s[i])dfs(i);
  for(int i=0;i<n;i++)cout<<a[i]+1<<" \n"[i==n-1];
}
