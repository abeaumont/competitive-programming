// https://cses.fi/problemset/task/1075/
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) cout << "1\n";
  else if (n <= 3) cout << "0\n";
  else {
    vector<long long> a(n + 1);
    a[0] = 1;
    a[1] = 1;
    a[2] = 0;
    a[3] = 0;
    for (int i = 4; i <= n; i++) a[i] = (a[i-1]*(i+1) - a[i-2]*(i-2) - a[i-3]*(i-5) + a[i-4]*(i-3)) % 1000000007;
    if (a[n] < 0) a[n] += 1000000007;
    cout << a[n] << endl;
  }
}
