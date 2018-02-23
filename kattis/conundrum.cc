// https://open.kattis.com/problems/conundrum
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (i % 3 == 0 && s[i] != 'P') c++;
    else if (i % 3 == 1 && s[i] != 'E') c++;
    else if (i % 3 == 2 && s[i] != 'R') c++;
  }
  cout << c << endl;
}
