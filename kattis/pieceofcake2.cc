// https://open.kattis.com/problems/pieceofcake2
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int n, h, v;
  cin >> n >> h >> v;
  cout << max(h, n - h) * max(v, n - v) * 4 << '\n';
}
