// https://codeforces.com/contest/1536/problem/B
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s;
string ans;

void search() {
  if (s.find(ans) == string::npos) return;
  int n = ans.size();
  if (ans.back() == 'z') {
    int i = 0;
    while (i < n) {
      if (ans[n - i - 1] == 'z') i++;
      else
        break;
    }
    if (i == n) {
      for (int j = 0; j < n; j++) ans[j] = 'a';
      ans.push_back('a');
      search();
      return;
    }
    ans[n - i - 1]++;
    for (int j = 0; j < i; j++) ans[n - j - 1] = 'a';
    search();
    return;
  }
  ans[n - 1]++;
  search();
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    ans = string("a");
    search();
    cout << ans << '\n';
  }
}
