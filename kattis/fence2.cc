// https://open.kattis.com/problems/fence2
#include <bits/stdc++.h>

using namespace std;
using dii = tuple<double, int, int>;
using vi = vector<int>;
using pq = priority_queue<dii>;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int k, n, num, den, c = 0;
  double w;
  pq q;
  cin >> k >> n;
  vi p(k);
  for (int i = 0; i < k; i++) {
    cin >> p[i];
    q.push({double(p[i]), p[i], 1});
  }
  for (int i = 0; i < n; i++) {
    tie(w, num, den) = q.top();
    q.pop();
    q.push({double(num) / (den + 1), num, den + 1});
  }
  for (int a : p) {
    a *= den;
    c += a / num;
    if (!(a % num)) c--;
  }
  cout << c << '\n';
}
