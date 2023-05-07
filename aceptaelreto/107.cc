// https://www.aceptaelreto.com/problem/statement.php?id=106
#include <bits/stdc++.h>

using namespace std;
const int N = 100000;
bool composite[N];
int pi[N];

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  for (int i = 4; i < N; i += 2) composite[i] = 1;
  for (int i = 3; i < N; i += 2)
    if (!composite[i])
      for (int j = i * 2; j < N; j += i) composite[j] = 1;
  for (int i = 2; i < N; i++) pi[i] = pi[i - 1] + !composite[i];
  int n, m;
  while (1) {
    cin >> n >> m;
    if (!n && !m) break;
    double error = pi[n] / double(n) - 1 / log(double(n));
    if (error < 0) error = -error;
    for (int i = 0; i < m; i++) error *= 10;
    if (error == 1) cout << "Igual\n";
    else if (error < 1)
      cout << "Menor\n";
    else
      cout << "Mayor\n";
  }
}
