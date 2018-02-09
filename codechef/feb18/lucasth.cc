// https://www.codechef.com/FEB18/problems/LUCASTH
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void s(vi &a, int p) {
  int n = a.size();
  vi b(n, 0);
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++)
      b[j] = (a[j - 1] + (i - 1) * a[j]) % p;
    swap(a, b);
    a[0] = 0;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, p;
    cin >> n >> p;
    n += 2;
    vi a(n, 0);
    s(a, p);
    int c = 0;
    for (int i = 0; i < n; i++)
      if (a[i] % p) c++;
    cout << c << endl;
  }
}
