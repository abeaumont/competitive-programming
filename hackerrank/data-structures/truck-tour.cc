// https://www.hackerrank.com/challenges/truck-tour
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  ll a[n],b[n],c=0,d=0,k=0;
  for (int i=0;i<n;i++) cin>>a[i]>>b[i];
  for (int i=0;i<n+k;i++) {
    c+=a[i%n];d+=b[i%n];
    while(c<d) {
      c-=a[k];d-=b[k];
      k++;
    }
  }
  cout<<k<<endl;
}
