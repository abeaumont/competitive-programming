// https://open.kattis.com/problems/cups
#include <algorithm>
#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, string> is;

int main() {
  int n;
  string s;
  cin >> n;
  getline(cin, s);
  vector<is> v(n);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    istringstream in(s);
    string a;
    int b;
    if (s[0] <= '9') {
      in >> b >> a;
      b /= 2;
    } else {
      in >> a >> b;
    }
    v[i] = make_tuple(b, a);
  }
  sort(v.begin(), v.end(), [](is a, is b) { return get<0>(a) < get<0>(b); });
  for (int i = 0; i < n; i++) {
    cout << get<1>(v[i]) << endl;
  }
}
