// https://codeforces.com/contest/989/problem/C
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using vii = vector<ii>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  string s = "ABCD";
  vii x = {{a, 0}, {b, 1}, {c, 2}, {d, 3}};
  sort(x.begin(), x.end());
  cout << 50 << ' ' << 50 << '\n';
  char ch1 = s[get<1>(x[3])];
  int c1 = get<0>(x[3]);
  char ch2 = s[get<1>(x[0])];
  int c2 = get<0>(x[0]);
  int i = 0;
  while (c1) {
    for (int j = 0; j < 50; j++) {
      if (!c1 || i%2 || j%2) cout << ch2;
      else cout << ch1, c1--;
    }
    cout << '\n';
    i++;
  }
  for (int j = 0; j < 50; j++) cout << ch2;
  cout << '\n';
  i++;
  ch1 = s[get<1>(x[2])];
  c1 = get<0>(x[2]);
  while (c1) {
    for (int j = 0; j < 50; j++) {
      if (!c1 || i%2 || j%2) cout << ch2;
      else cout << ch1, c1--;
    }
    cout << '\n';
    i++;
  }
  for (int j = 0; j < 50; j++) cout << ch2;
  cout << '\n';
  i++;
  ch1 = s[get<1>(x[1])];
  c1 = get<0>(x[1]);
  while (c1>1) {
    for (int j = 0; j < 50; j++) {
      if (c1<=1 || i%2 || j%2) cout << ch2;
      else cout << ch1, c1--;
    }
    cout << '\n';
    i++;
  }
  for (int j = 0; j < 50; j++) cout << ch2; cout << '\n';
  for (int j = 0; j < 50; j++) cout << ch1; cout << '\n';
  i += 2;
  while (c2>1) {
    for (int j = 0; j < 50; j++) {
      if (c2<=1 || i%2 || j%2) cout << ch1;
      else cout << ch2, c2--;
    }
    cout << '\n';
    i++;
  }
  for (;i<50;i++) {
    for (int j = 0; j < 50; j++) cout << ch1;
    cout << '\n';
  }
}
