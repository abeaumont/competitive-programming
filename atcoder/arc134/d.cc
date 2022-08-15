// https://atcoder.jp/contests/arc134/tasks/arc134_d
#include <bits/stdc++.h>

using namespace std;
struct pr {
  int x, y, i;

  bool operator<(const pr o) const {
    return x < o.x || x == o.x && y < o.y || x == o.x && y == o.y && i < o.i;
  }
};

struct pri {
  int x, y, i;
  pri() : x(0), y(0), i(0) {}
  pri(pr p) : x(p.x), y(p.y), i(p.i) {}

  bool operator<(const pri o) const { return i > o.i; }
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pr> a(n);
  vector<pair<int, int>> b(n);
  for (int i = 0; i < n; i++) cin >> a[i].x;
  for (int i = 0; i < n; i++) cin >> a[i].y;
  for (int i = 0; i < n; i++) a[i].i = i;
  for (int i = 0; i < n; i++) b[a[i].i] = {a[i].x, a[i].y};
  set<pr> s;
  for (int i = 0; i < n; i++) s.insert(a[i]);
  set<pri> si;
  for (int i = 0; i < n; i++) si.insert(pri(a[i]));

  auto it = s.begin();
  if (it->y <= it->x) {
    cout << it->x << ' ' << it->y << '\n';
    return 0;
  }
  int upper = 0, upnext;
  vector<int> ans;
  while (it != s.end()) {
    int x = it->x;
    if (upper && (x > upper || x == upper && upnext <= upper)) break;
    vector<pr> r;
    r.push_back(*it);
    while (++it != s.end() && it->x == x) r.push_back(*it);
    sort(r.begin(), r.end(),
         [&](const pr &a, const pr &b) { return a.i < b.i; });
    if (!upper) upper = r[0].y, upnext = upper;
    for (auto pr : r) {
      if (upnext == upper) upnext = pr.y;
      ans.push_back(pr.i);
    }
    if (it == s.end()) break;
    auto it2 = next(si.find(pri(r.back())));
    while (it2 != si.end()) {
      r.push_back({it2->x, it2->y, it2->i});
      ++it2;
    }
    for (auto pr : r) {
      s.erase(pr);
      si.erase(pri(pr));
    }
    it = s.begin();
  }
  for (int i = 0; i < ans.size(); i++) cout << b[ans[i]].first << ' ';
  for (int i = 0; i < ans.size(); i++)
    cout << b[ans[i]].second << " \n"[i == ans.size() - 1];
}
