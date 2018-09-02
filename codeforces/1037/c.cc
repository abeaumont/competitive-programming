// https://codeforces.com/contest/1037/problem/C
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  int i = 0, c= 0;
  while (i < n - 1) {
    if (a[i] == b[i]) i++;
    else if (a[i+1] == b[i+1] || a[i] != a[i+1]) {
      c++;
      i+=2;
    } else {
      c++;
      i++;
    }
  }
  if (i == n - 1 && a[i] != b[i]) c++;
  cout << c << endl;
}
