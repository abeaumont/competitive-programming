// https://www.codechef.com/SEPT18A/problems/BSHUFFLE
#include <iostream>

using namespace std;

const int N = 17;
int n, a[N];

int main() {
  cin >> n;
  for (int i=0; i < n; i++) a[i]=i+2;
  a[(n+1)/2-1] = 1;
  a[n-1] = (n+1)/2+1;
  for (int i = 0; i < n; i++) {
    cout << a[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
  cout << n;
  for (int i = 1; i < n; i++) cout << " " << i;
  cout << endl;
}
