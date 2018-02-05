// https://www.codechef.com/FEB18/problems/CHEFCHR
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int c = 0;
    for (int i = 0; i + 4 <= s.size(); i++) {
      string u = s.substr(i, 4);
      sort(u.begin(), u.end());
      if (u == "cefh") c++;
    }
    if (c) cout << "lovely " << c << endl;
    else cout << "normal\n";
  }
}
