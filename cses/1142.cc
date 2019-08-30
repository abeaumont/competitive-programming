// https://cses.fi/problemset/task/1142/
#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

typedef stack<int> si;
typedef vector<int> vi;
typedef long long ll;

int main() {
  int n; cin >> n;
  vi v(n+1, 0);
  for (int i = 0; i < n; i++) cin >> v[i];
  ll m = 0;
  si s;
  for (int i = 0; i <= n; i++) {
    while (!s.empty() && v[i] <= v[s.top()]) {
      int h = v[s.top()];
      s.pop();
      int k = s.empty() ? -1 : s.top();
      m = max(m, ll(i - k - 1) * h);
    }
    s.push(i);
  }
  cout << m << endl;
}
