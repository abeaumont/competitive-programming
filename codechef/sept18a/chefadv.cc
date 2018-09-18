// https://www.codechef.com/SEPT18A/problems/CHEFADV
#include <iostream>

using namespace std;

int main() {
  int t,n,m,x,y;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x >> y;
    if ((n-1)%x == 0 && (m-1)%y == 0 || n>1 && m>1 && (n-2)%x == 0 && (m-2)%y == 0) cout << "Chefirnemo\n";
    else cout << "Pofik\n";
  }
}
