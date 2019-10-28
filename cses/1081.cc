// https://cses.fi/problemset/task/1081/
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef unordered_set<int> si;

const int X = 1000000;
int a[X+1];
bool d[X+1];
int m;

void divisors(vi& f, si& s, int i, int x) {
  if (i == f.size()) {
    s.insert(x);
    return;
  }
  divisors(f, s, i + 1, x);
  divisors(f, s, i + 1, x * f[i]);
}

int main() {
  for (int i = 2; i <= X; i++) {
    if (a[i]) continue;
    for (int j = 2*i; j <= X; j += i)
      a[j] = i;
  }
  int n;
  cin >> n;
  while (n--) {
    int x; cin >> x;
    if (x <= m) continue;
    vi f;
    while (a[x]) {
      f.push_back(a[x]);
      x /= a[x];
    }
    f.push_back(x);
    si s;
    divisors(f, s, 0, 1);
    for (auto c:s) {
      if (d[c]) m = max(m, c);
      else d[c] = true;
    }
  }
  cout << m << endl;
}
