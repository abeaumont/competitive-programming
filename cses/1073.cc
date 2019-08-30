// https://cses.fi/problemset/task/1073/
#include <iostream>
#include <set>

using namespace std;

int main() {
  int n, x;
  cin >> n;
  multiset<int> s;
  while (n--) {
    cin >> x;
    auto it = s.lower_bound(x + 1);
    if (it == s.end()) s.insert(x);
    else {
      s.erase(it);
      s.insert(x);
    }
  }
  cout << s.size() << endl;
}
