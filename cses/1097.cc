// https://cses.fi/problemset/task/1097/
#include <iostream>

using namespace std;

typedef long long ll;

ll a[5001][5001];
ll b[5001][5001];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[0][i];
  for (int i = 1; i < n; i++)
    for (int j = 0; j < n - i; j++) {
      ll t = a[0][j] + a[i - 1][j + 1] + b[i - 1][j + 1];
      a[i][j] = max(a[0][j] + b[i - 1][j + 1], a[0][j + i] + b[i - 1][j]);
      b[i][j] = t - a[i][j];
    }
  cout << a[n - 1][0] << endl;
}
