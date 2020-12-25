// https://open.kattis.com/problems/greedilyincreasing
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, x;
  cin >> n;
  vector<int> ans(1);
  cin >> ans[0];
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (x > ans.back()) ans.push_back(x);
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " \n"[i == ans.size() - 1];
}
