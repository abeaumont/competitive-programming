// https://cses.fi/problemset/task/1131/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_set>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<ii> qii;
typedef unordered_set<int> si;

int main() {
  int n;
  cin >> n;
  vvi g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  qii q;
  si s;
  q.push({0, 0});
  s.insert(0);
  int a, k;
  while (!q.empty()) {
    tie(a, k) = q.front();
    q.pop();
    for (auto z : g[a]) {
      if (s.count(z)) continue;
      s.insert(z);
      q.push({z, k + 1});
    }
  }
  s.clear();
  q.push({a, 0});
  s.insert(a);
  while (!q.empty()) {
    tie(a, k) = q.front();
    q.pop();
    for (auto z : g[a]) {
      if (s.count(z)) continue;
      s.insert(z);
      q.push({z, k + 1});
    }
  }
  cout << k << endl;
}
