// https://www.hackerearth.com/challenge/competitive/january-circuits-18/approximate/array-construction-410b758b/
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int, int, int> iii;
typedef priority_queue<iii> pq;

int main() {
  int n, m;
  cin >> n >> m;
  vvi v(n);
  pq pq;
  for (int i = 0; i < n; i++) {
    v[i] = vi(n);
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
      pq.push(make_tuple(-v[i][j], i, j));
    }
  }
  int q = m / n;
  int r = m % n;
  vb x(n, 0);
  int k = 0;
  int t = max(r, n - r);
  while (k < t) {
    int a, b, c;
    tie(a, b, c) = pq.top();
    pq.pop();
    if (!x[b]) {
      x[b] = true;
      k++;
      if (k == t) break;
    }
    if (!x[c]) {
      x[c] = true;
      k++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (x[i]) {
      if (t == r) cout << q + 1;
      else cout << q;
    } else {
      if (t == r) cout << q;
      else cout << q + 1;
    }
    if (i < n - 1) cout << " ";
    else cout << endl;
  }
}
