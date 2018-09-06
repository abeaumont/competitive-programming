// https://codeforces.com/contest/1038/problem/B
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 45000;
int a[N];

int main() {
  ll n, s;
  cin >> n;
  if (n < 3) { cout << "No\n"; return 0; }
  cout << "Yes\n";
  cout << "1 " << n << endl;
  cout << n-1;
  for (int i = 1; i <= n - 1; i++) cout << " " << i;
  cout << endl;
}
