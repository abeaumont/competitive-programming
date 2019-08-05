// https://cses.fi/problemset/task/1158/
#include <iostream>

using namespace std;

int h[1001];
int s[1001];
int a[100002];

int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) cin >> h[i];
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = x; j >= 1; j--)
      if (h[i] <= j)
        a[j] = max(a[j], a[j - h[i]] + s[i]);
  cout << a[x] << endl;
}
