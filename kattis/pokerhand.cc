// https://open.kattis.com/problems/pokerhand
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  unordered_map<char, int> m;
  for (int i = 0; i < 5; i++) {
    cin >> s;
    m[s[0]]++;
  }
  int mx = 0;
  for (auto it : m) mx = max(it.second, mx);
  cout << mx << '\n';
}
