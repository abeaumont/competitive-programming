// https://cses.fi/problemset/task/1149/
#include <iostream>

using namespace std;

int d[500001], l[26], M = 1000000007;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  d[0] = 1;
  for (int i = 1; i <= n; i++) {
    d[i] = d[i-1]*2%M;
    int c = s[i-1]-'a';
    if (l[c]) d[i] = (d[i]-d[l[c]-1])%M;
    l[c] = i;
  }
  int r = (d[n]-1)%M;
  if (r < 0) r+=M;
  cout << r << endl;
}
