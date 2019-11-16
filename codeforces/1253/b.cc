// https://codeforces.com/contest/1253/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using si = unordered_set<int>;

bool a[1000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n;
  bool ok = 1;
  int c = 0, s = 0;
  vi r;
  si b;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x < 0) {
      if (!a[-x]) {
        ok = 0;
        break;
      }
      a[-x] = 0;
      c--;
      if (!c) {
        r.push_back(i - s + 1);
        s = i + 1;
        b.clear();
      }
    } else {
      if (b.count(x) || a[x]) {
        ok = 0;
        break;
      }
      b.insert(x);
      a[x] = 1;
      c++;
    }
  }
  if (c) ok = 0;
  if (ok) {
    cout << r.size() << "\n";
    for (int i = 0; i < r.size(); i++)
      cout << r[i] << " \n"[i == r.size() - 1];
  } else cout << "-1\n";
}
