// https://codeforces.com/contest/1227/problem/C
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vii = vector<ii>;

string s;

int find(int i, char c) {
  while (s[++i] != c);
  return i;
}

int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    vii r;
    int l = n / 2 - k + 1, a = -1, b = -1;
    for (int i = 0; i < l; i++)
      if ((a = find(a, '(')) > i)
        swap(s[i], s[a]), r.push_back({i, a});
    for (int i = l; i < 2*l; i++)
      if ((b = find(b, ')')) > i)
        swap(s[i], s[b]), r.push_back({i, b});
    for (int i = 2*l; i < n; i++) {
      if ((a = find(a, '(')) > i)
        swap(s[i], s[a]), r.push_back({i, a});
      i++;
      if ((b = find(b, ')')) > i)
        swap(s[i], s[b]), r.push_back({i, b});
    }
    cout << r.size() << '\n';
    for (ii x : r) {
      tie(a, b) = x;
      cout << a + 1 << ' ' << b + 1 << '\n';
    }
  }
}
