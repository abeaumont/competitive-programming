// https://www.codechef.com/FEB18/problems/CHANOQ
#include <cmath>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef unordered_map<int, int> mii;
typedef unordered_set<int> si;

struct node {
  int start;
  int end;
  vi intervals;
};

typedef vector<node> vn;

int ipow(int b, int e) {
  int r = 1;
  for (int i = 0; i < e; i++) r *= b;
  return r;
}

void insert(vn &v, int i, int a, int b, int k) {
  if (a <= v[i].start && b >= v[i].end) {
    v[i].intervals.push_back(k);
    return;
  }
  if (a <= v[i*2].end) insert(v, i * 2, a, b, k);
  if (b >= v[i*2+1].start) insert(v, i * 2 + 1, a, b, k);
}

void find(const vn &v, si &r, int i, int x) {
  if (v[i].start > x || v[i].end < x) return;
  for (auto z : v[i].intervals) r.insert(z);
  if (v[i].start != v[i].end) {
    find(v, r, i * 2, x);
    find(v, r, i * 2 + 1, x);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vii r;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      r.push_back(make_tuple(--a, --b));
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
    for (int i = 0; i < n; i++) {
      int a, b;
      tie(a, b) = r[i];
      insert(v, 1, a, b, i);
    }
    int q;
    cin >> q;
    while (q--) {
      int m;
      cin >> m;
      mii s;
      while (m--) {
        int x;
        cin >> x;
        si a;
        find(v, a, 1, x - 1);
        for (auto z : a) s[z]++;
      }
      int c = 0;
      for (auto z : s)
        if (z.second % 2) c++;
      cout << c << endl;
    }
  }
}
