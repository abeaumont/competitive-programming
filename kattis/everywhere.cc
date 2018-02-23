// https://open.kattis.com/problems/everywhere
#include <iostream>
#include <unordered_set>

using namespace std;

typedef unordered_set<string> ss;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ss s;
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) {
      string u;
      cin >> u;
      s.insert(u);
    }
    cout << s.size() << endl;
  }
}
