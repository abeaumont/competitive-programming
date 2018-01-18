// https://open.kattis.com/problems/evenup
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef stack<int> si;

int main() {
  int n;
  cin >> n;
  vi v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int i = 0;
  int c = n;
  si s;
  while (i < n) {
    if (!s.empty() && s.top() % 2 == v[i] % 2) {
      s.pop();
      i++;
      c -= 2;
    } else if (i < n - 1 && v[i] % 2 == v[i + 1] % 2) {
      c -= 2;
      i += 2;
    } else {
      s.push(v[i]);
      i++;
    }
  }
  cout << c << endl;;
}
