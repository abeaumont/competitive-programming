// https://www.aceptaelreto.com/problem/statement.php?id=103
#include <bits/stdc++.h>

using namespace std;
const int N = 20;
int p[N], n;

double f(double x) {
  double sum = 0;
  for (int i = 0; i <= n; i++) {
    double exp = 1;
    for (int j = 0; j < i; j++) exp *= x;
    sum += exp * p[i];
  }
  if (sum < 0) return 0;
  if (sum > 1) return 1;
  return sum;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  while (1) {
    int m;
    cin >> n;
    if (n == 20) break;
    for (int i = 0; i <= n; i++) cin >> p[n - i];
    cin >> m;
    double area = 0;
    for (int i = 0; i < m; i++) {
      double x = 1 / double(m);
      area += x * f(x * i);
    }
    if (area - 0.5 > 0.001) cout << "CAIN\n";
    else if (0.5 - area > 0.001)
      cout << "ABEL\n";
    else
      cout << "JUSTO\n";
  }
}
