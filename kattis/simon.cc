// https://open.kattis.com/problems/simon
#include <iostream>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    if (s.find("simon says ") != string::npos) {
      cout << s.substr(11) << endl;
    } else {
      cout << endl;
    }
  }
}
