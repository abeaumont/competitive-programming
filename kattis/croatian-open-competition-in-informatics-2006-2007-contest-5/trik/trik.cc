// https://open.kattis.com/problems/trik
#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int p = 1;
  for (unsigned char c : s) {
    switch(c) {
    case 'A':
      switch(p) {
      case 1:
        p = 2;
        break;
      case 2:
        p = 1;
        break;
      }
      break;
    case 'B':
      switch(p) {
      case 2:
        p = 3;
        break;
      case 3:
        p = 2;
        break;
      }
      break;
    case 'C':
      switch(p) {
      case 1:
        p = 3;
        break;
      case 3:
        p = 1;
        break;
      }
      break;
    }
  }
  cout << p << endl;
}
