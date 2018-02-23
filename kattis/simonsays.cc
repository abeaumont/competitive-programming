// https://open.kattis.com/problems/simonsays
#include <iostream>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    if (s.find("Simon says ") != string::npos) {
      cout << s.substr(11) << endl;
    }
  }
}
