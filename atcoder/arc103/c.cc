// https://arc103.contest.atcoder.jp/tasks/arc103_a
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100000;
int a[N+1], b[N+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (i%2) {
      b[x]++;
    } else {
      a[x]++;
    }
  }
  int ma = 0, ai = 0;
  int mb = 0, bi = 0;
  for (int i = 0; i <= N; i++) {
    if (a[i] > ma) {
      ma = a[i];
      ai = i;
    }
    if (b[i] > mb) {
      mb = b[i];
      bi = i;
    }
  }
  int s = ma+mb;
  if (ai == bi) {
    int m = 0;
    for (int i = 0; i <= N; i++) {
      if (i == ai) continue;
      m = max(m, a[i]);
    }
    s = mb+m;
    m = 0;
    for (int i = 0; i <= N; i++) {
      if (i == bi) continue;
      m = max(m, b[i]);
    }
    s = max(s, ma+m);
  }
  cout << n - s << endl;
}
