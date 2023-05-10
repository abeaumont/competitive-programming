// https://open.kattis.com/problems/cheatingatwar
#include <bits/stdc++.h>

using namespace std;

string order = "23456789TJQKA";

bool cmp(const char &a, const char &b) {
  for (char c : order)
    if (a == c) return 1;
    else if (b == c)
      return 0;
  return 1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  while (n--) {
    string s1, s2;
    cin >> s1 >> s2;
    stable_sort(s1.begin(), s1.end(), cmp);
    stable_sort(s2.begin(), s2.end(), cmp);
    int best = 0;
    for (int i = 0; i < 26; i++) {
      int sum = 0;
      for (int j = 0; j + i < 26; j++)
        if (s1[j] == s2[j + i]) sum++;
        else if (cmp(s1[j], s2[j + i]))
          sum += 2;
      best = max(best, sum);
    }
    cout << best << '\n';
  }
}
