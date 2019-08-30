// https://cses.fi/problemset/task/1188/
#include <iostream>
#include <map>
#include <set>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;
typedef set<ii> sii;
typedef map<int, int, greater<int>> mii;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  mii m;
  sii a;
  int c = 1;
  char b = s[0];
  for (int i = 1; i < n; i++) {
    if (s[i] == b) c++;
    else {
      m[i - c] = c;
      a.insert({c, i - c});
      b = s[i];
      c = 1;
    }
  }
  m[n - c] = c;
  a.insert({c, n - c});
  int t, x;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x;
    x--;
    auto it = m.lower_bound(x);
    a.erase({it->second, it->first});
    if (it->first == x) {
      if (it->second == 1) {
        int k = it->first;
        int c = it->second;
        auto next = it;
        next--;
        auto prev = it;
        prev++;
        if (next != m.end()) {
          c += next->second;
          a.erase({next->second, next->first});
          m.erase(next);
        }
        if (prev != m.end()) {
          k = prev->first;
          c += prev->second;
          a.erase({prev->second, prev->first});
          m.erase(prev);
        }
        m.erase(it);
        a.insert({c, k});
        m[k] = c;
      } else {
        int k = it->first;
        int c = it->second;
        auto prev = it;
        prev++;
        a.erase({it->second, it->first});
        if (prev != m.end()) {
          int k2, c2;
          k2 = prev->first;
          c2 = prev->second;
          m.erase(prev);
          a.erase({c2, k2});
          m[k2] = c2 + 1;
          a.insert({c2 + 1, k2});
          m.erase(it);
        } else {
          m.erase(it);
          m[k] = 1;
          a.insert({1, k});
        }
        m[k + 1] = c - 1;
        a.insert({c - 1, k + 1});
      }
    } else {
      int k = it->first;
      int c = it->second;
      int d = x - it->first;
      if (c == d + 1) {
        auto next = it;
        next--;
        int c2 = 0;
        if (next != m.end()) {
          int k2 = next->first;
          c2 = next->second;
          m.erase(next);
          a.erase({c2, k2});
        }
        m[x] = c2 + 1;
        a.insert({c2 + 1, x});
      } else {
        m[x] = 1;
        a.insert({1, x});
        m[x + 1] = c - d - 1;
        a.insert({c - d - 1, x + 1});
      }
      a.erase({c, k});
      m.erase(it);
      m[k] = d;
      a.insert({d, k});
      
    }
    int c, k;
    tie(c, k) = *a.rbegin();
    cout << c;
    if (i < t - 1) cout << " ";
  }
  cout << endl;
}
