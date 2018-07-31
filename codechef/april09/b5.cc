// https://www.codechef.com/APRIL09/problems/B5
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;
typedef deque<ii> dqii;

int n, k, m[1001][1001], x[1001][1001], y[1001][1001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> m[i][j];
  for (int i = 0; i < n; i++) {
    dqii q;
    for (int j = 0; j < k; j++) {
      while (!q.empty()) {
        int u, v;
        tie(u, v) = q.back();
        if (v < m[i][j]) break;
        q.pop_back();
      }
      q.push_back({j, m[i][j]});
    }
    for (int j = 0; j < n - k; j++) {
      int u, v;
      tie(u, v) = q.front();
      x[i][j] = v;
      if (u <= j) q.pop_front();
      while (!q.empty()) {
        int u, v;
        tie(u, v) = q.back();
        if (v < m[i][j+k]) break;
        q.pop_back();
      }
      q.push_back({j+k, m[i][j+k]});
    }
    x[i][n - k] = get<1>(q.front());
  }
  for (int j = 0; j < n - k + 1; j++) {
    dqii q;
    for (int i = 0; i < k; i++) {
      while (!q.empty()) {
        int u, v;
        tie(u, v) = q.back();
        if (v < x[i][j]) break;
        q.pop_back();
      }
      q.push_back({i, x[i][j]});
    }
    for (int i = 0; i < n - k; i++) {
      int u, v;
      tie(u, v) = q.front();
      y[i][j] = v;
      if (u <= i) q.pop_front();
      while (!q.empty()) {
        int u, v;
        tie(u, v) = q.back();
        if (v < x[i+k][j]) break;
        q.pop_back();
      }
      q.push_back({i+k, x[i+k][j]});
    }
    y[n - k][j] = get<1>(q.front());
  }
  for (int i = 0; i < n - k + 1; i++) {
    for (int j = 0; j < n - k + 1; j++) {
      cout << y[i][j];
      if (j < n - k) cout << " ";
    }
    cout << endl;
  }
}
