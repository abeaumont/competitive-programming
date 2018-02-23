// https://open.kattis.com/problems/anothercandies
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int mod = 0;
    for (int j = 0; j < n; j++) {
      long long x;
      cin >> x;
      mod += x % n;
    }
    cout << (mod % n ? "NO" : "YES") << endl;
  }
}

