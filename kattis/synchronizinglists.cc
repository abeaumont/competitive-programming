// https://open.kattis.com/problems/synchronizinglists
#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef unordered_map<int, int> mii;

int main() {
  bool first = true;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    if (first) first = false;
    else cout << endl;
    vi a(n);
    vi b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vi c(n);
    copy(a.begin(), a.end(), c.begin());
    sort(c.begin(), c.end());
    sort(b.begin(), b.end());
    mii m;
    for (int i = 0; i < n; i++) m[c[i]] = b[i];
    for (int i = 0; i < n; i++) {
      mii::iterator it = m.find(a[i]);
      cout << it->second << endl;
    }
  }
}
