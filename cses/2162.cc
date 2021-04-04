// https://cses.fi/problemset/task/2162
#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  list<int> xs;
  for (int i = 1; i <= n; i++) xs.push_back(i);
  auto it = xs.begin();
  while (!xs.empty()) {
    it++;
    if (it == xs.end()) it = xs.begin();
    cout << *it;
    it = xs.erase(it);
    cout << " \n"[xs.empty()];
    if (it == xs.end()) it = xs.begin();
  }
}
