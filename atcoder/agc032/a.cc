// https://atcoder.jp/contests/agc032/tasks/agc032_a
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(){
  int n;
  cin >> n;
  vi a, b(n);
  for (int i = 0; i < n; i++) cin >> b[i], b[i]--;
  for (int i = 0; i < n; i++) {
    if (b[i] > a.size()) {
      cout << "-1\n";
      return 0;
    }
    a.insert(a.begin() + b[i], b[i] + 1);
  }
  for(int x : a) cout << x << '\n';
}
