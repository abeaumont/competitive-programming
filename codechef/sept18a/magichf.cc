// https://www.codechef.com/SEPT18A/problems/MAGICHF
#include <iostream>

using namespace std;

int t,n,x,s,a,b;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x >> s;
    for (int i = 0; i < s; i++) {
      cin >> a >> b;
      if (x == a) x = b;
      else if (x == b) x = a;
    }
    cout << x << endl;
  }
}
