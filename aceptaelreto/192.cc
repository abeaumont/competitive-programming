// https://www.aceptaelreto.com/problem/statement.php?id=192
#include <bits/stdc++.h>

using namespace std;

const int N = 20000;
bool a[N+1];

int main() {
  a[1] = 1;
  for (int i = 1; i <= N; i++)
    if (a[i]) {
      int x = i * 3;
      if (x <= N) a[x] = 1;
      x = i + 5;
      if (x <= N) a[x] = 1;
    }
  while (1) {
    int n;
    cin >> n;
    if (!n) break;
    if (a[n]) cout << "SI\n";
    else cout << "NO\n";
  }
}
