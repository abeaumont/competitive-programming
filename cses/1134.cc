// https://cses.fi/problemset/task/1134
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;

const int N = 500000;
int a[N], c[N];
ii b[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 2; i++) {
    cin >> c[i];
    a[c[i]-1] = i + 1;
  }
  for (int i = 0; i < n; i++) b[i] = {a[i], i};
  sort(b, b+n);
  priority_queue<int, vector<int>, greater<int>> q;
  int i = 0;
  for (; i < n; i++) {
    int k, x;
    tie(k, x) = b[i];
    if (k > 0) break;
    q.push(x + 1);
  }
  for (int j = 0; j < n - 2; j++) {
    cout << q.top() << " " << c[j] << endl;
    q.pop();
    for (;i < n; i++) {
      int k, x;
      tie(k, x) = b[i];
      if (k > j + 1) break;
      q.push(x + 1);
    }
  }
  cout << c[n - 3] << " " << n << endl;
}
