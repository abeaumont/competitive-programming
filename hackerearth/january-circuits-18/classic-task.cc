// https://www.hackerearth.com/challenge/competitive/january-circuits-18/algorithm/classic-task-39656dbf/
#include <cmath>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<ii> vii;
typedef unordered_set<int> si;

struct node {
  int start;
  int end;
  vii intervals;
};

typedef vector<node> vn;

int ipow(int b, int e) {
  int r = 1;
  for (int i = 0; i < e; i++) r *= b;
  return r;
}

void insert(vn &v, int i, int a, int b) {
  if (a <= v[i].start && b >= v[i].end) {
    v[i].intervals.push_back(make_tuple(a, b));
    return;
  }
  if (a <= v[i*2].end) insert(v, i * 2, a, b);
  if (b >= v[i*2+1].start) insert(v, i * 2 + 1, a, b);
}

void find(const vn &v, vii &r, int i, int x) {
  if (v[i].start > x || v[i].end < x) return;
  for (auto z : v[i].intervals) r.push_back(z);
  if (v[i].start != v[i].end) {
    find(v, r, i * 2, x);
    find(v, r, i * 2 + 1, x);
  }
}

void dfs(const vn &v, si &s, int x) {
  vii r;
  find(v, r, 1, x);
  for (auto n : r) {
    int a, b;
    tie(a, b) = n;
    if (x - a == b - x) continue;
    int y;
    if (x - a < b - x) {
      int d = x - a;
      y = b - d;
    } else {
      int d = b - x;
      y = a + d;
    }
    auto it = s.find(y);
    if (it != s.end()) {
      s.erase(it);
      dfs(v, s, *it);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vii r;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (a == b) continue;
    r.push_back(make_tuple(--a, --b));
  }
  if (n == 1 || r.size() == 0) {
    cout << n << endl;
    return 0;
  }
  int k = ipow(2, log2(n - 1) + 1);
  vn v(2 * k);
  for (int j = k; j < k + n; j++) v[j] = {j - k, j - k, {}};
  for (int j = k + n; j < 2 * k; j++) v[j] = {v[j-1].start, v[j-1].end, {}};
  for (int i = k - 1; i > 0; i--) {
    int a = i * 2;
    int b = i * 2 + 1;
    v[i] = {v[a].start, v[b].end, {}};
  }
  for (auto x : r) {
    int a, b;
    tie(a, b) = x;
    insert(v, 1, a, b);
  }
  si s;
  for (int i = 0; i < n; i++) s.insert(i);
  int c = 0;
  while (!s.empty()) {
    auto it = s.begin();
    s.erase(it);
    dfs(v, s, *it);
    c++;
  }
  cout << c << endl;
}
