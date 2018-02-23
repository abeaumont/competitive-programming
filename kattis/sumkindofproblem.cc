// https://open.kattis.com/problems/sumkindofproblem
#include <iostream>

using namespace std;

int main() {
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int k, n;
    cin >> k >> n;
    int s1 = n * (n + 1) / 2;
    int s2 = n * n;
    int s3 = n * (n + 1);
    cout << k << " " << s1 << " " << s2 << " " << s3 << endl;
  }
}
