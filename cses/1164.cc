// https://cses.fi/problemset/task/1164/
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef tuple<int, int> ii;
typedef multimap<ii, int> miii;
typedef priority_queue<ii, vector<ii>, greater<ii>> pq;

int main() {
  int n, k = 0;
  cin >> n;
  miii m;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    m.insert(make_pair(make_tuple(a, b), i));
  }
  pq q;
  vi v(n);
  for (auto it = m.begin(); it != m.end(); it++) {
    int a, b, c;
    tie(a, b) = it->first;
    if (q.empty() || get<0>(q.top()) >= a) {
      c = ++k;
    } else {
      c = get<1>(q.top());
      q.pop();
    }
    q.push(make_tuple(b, c));
    v[it->second] = c;
  }
  cout << k << endl;
  for (int i = 0; i < n; i++) {
    cout << v[i];
    if (i < n - 1) cout << " ";
  }
  cout << endl;
}
