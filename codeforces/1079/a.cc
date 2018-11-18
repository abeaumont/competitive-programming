// https://codeforces.com/contest/1079/problem/A
#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;
int a[101];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    a[x]++;
  }
  int m=0,l=0;
  for(int i=0;i<=100;i++){
    if(a[i])l++;
    m=max(m,a[i]);
  }
  int d=(m-1)/k+1;
  cout<<d*l*k-n<<endl;
}
