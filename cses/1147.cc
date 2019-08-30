// https://cses.fi/problemset/task/1147/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef stack<int> si;
typedef vector<int> vi;

int n, m, M;
vi a;

int f() {
  si s;
  int x = 0;
  for (int i = 0; i <= m; i++) {
    while (!s.empty() && a[i] < a[s.top()]) {
      int h = a[s.top()]; s.pop();
      int k = s.empty() ? -1 : s.top();
      x = max(x, h * (i - k - 1));
    }
    s.push(i);
  }
  return x;
}

int main() {
  cin >> n >> m;
  a = vi(m + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      if (c == '.') a[j]++;
      else a[j] = 0;
    }
    M = max(M, f());
  }
  cout << M << endl;
}
