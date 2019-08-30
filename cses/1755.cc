// https://cses.fi/problemset/task/1755/
#include <bits/stdc++.h>

using namespace std;

int main() {
  string s, r;
  cin >> s;
  vector<int> a(26);
  for (char c : s) a[c-'A']++;
  int odd = 0;
  for (int i = 0; i < 26; i++)
    odd += a[i] % 2;
  if (odd > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  for (int i = 0; i < 26; i++)
    if (!(a[i] % 2))
      for (int j = 0; j < a[i] / 2; j++)
        r.push_back(i + 'A');
  for (int i = 0; i < 26; i++)
    if (a[i] % 2)
      for (int j = 0; j < a[i]; j++)
        r.push_back(i + 'A');
  for (int i = 25; i >= 0; i--)
    if (!(a[i] % 2))
      for (int j = 0; j < a[i] / 2; j++)
        r.push_back(i + 'A');
  cout << r << "\n";
}
