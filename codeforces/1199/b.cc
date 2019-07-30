// https://codeforces.com/contest/1199/problem/B
#include <bits/stdc++.h>

using namespace std;

int main() {
  double h, l;
  cin >> h >> l;
  cout << fixed << setprecision(20) << (l * l + h * h) / (2 * h) - h << endl;
}
