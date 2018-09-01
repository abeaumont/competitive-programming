#include <cassert>
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(int argc, char *argv[]) {
  assert(argc > 1);
  int l = atoi(argv[1]);
  assert(l >= 0 && l <= 1000000);
  int n, m;
  cin >> n >> m;
  assert(n >= 1 && n <= 20);
  assert(m >= 1 && m <= 60);
  vvii g(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    assert(a >= 1 && a <= n);
    assert(b >= 1 && b <= n);
    assert(a < b);
    assert(c >= 0 && c < l);
    a--; b--;
    g[a].push_back({b, c});
  }
  vb s(l);
  function<void(int, int)> dfs = [&](int i, int k) {
    if (i == n - 1) {
      assert(k >= 0 && k <= l - 1);
      assert(!s[k]);
      s[k] = true;
      return;
    }
    for (auto z:g[i]) {
      int b, c;
      tie(b, c) = z;
      dfs(b, k + c);
    }
  };
  dfs(0, 0);
  for (int i = 0; i < l; i++) assert(s[i]);
}
