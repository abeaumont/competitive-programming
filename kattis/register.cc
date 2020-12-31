// https://open.kattis.com/problems/register
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int c = 0, k = 1, x;
  for (int i : {2, 3, 5, 7, 11, 13, 17, 19}) {
    cin >> x;
    c += x * k;
    k *= i;
  }
  cout << 9699689 - c << '\n';
}
