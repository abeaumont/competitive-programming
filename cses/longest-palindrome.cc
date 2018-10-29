//https://cses.fi/problemset/task/1111/
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vi a(n),b(n);
  for (int i=0,l=0,r=-1;i<n;i++) {
    int k=i>r?1:min(a[l+r-i],r-i);
    while (i>=k&&i+k<n&&s[i-k]==s[i+k]) k++;
    a[i]=k--;
    if(i+k>r) {
      l=i-k;
      r=i+k;
    }
  }
  for (int i=0,l=0,r=-1;i<n;i++) {
    int k=i>r?0:min(b[l+r-i+1],r-i+1);
    while (i>=k+1&&i+k<n&&s[i-k-1]==s[i+k]) k++;
    b[i]=k--;
    if(i+k>r) {
      l=i-k-1;
      r=i+k;
    }
  }
  int m=0,k;
  for (int i=0;i<n;i++) {
    if(a[i]>m){
      m=a[i];
      k=i;
    }
    if(b[i]>=m){
      m=b[i];
      k=i;
    }
  }
  cout<<(a[k]>b[k]?s.substr(k-a[k]+1,a[k]*2-1):s.substr(k-b[k],b[k]*2))<<endl;
}
