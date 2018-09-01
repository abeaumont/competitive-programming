// https://arc102.contest.atcoder.jp/tasks/arc102_b
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

int main(int argc, char *argv[]) {
  int l;
  cin >> l;
  viii edges;
  int i = 1, j = 1;
  for (; i * 2 <= l; i *= 2);
  l -= i;
  int x = i;
  for (i /= 2; i >= 1; i /= 2, j++) {
    edges.push_back({j, j + 1, 0});
    edges.push_back({j, j + 1, i});
  }
  int n = j;
  int k = 0;
  for (int i = 20; i >= 0; i--) {
    if (l & (1 << i)) {
      x += k;
      k = 1 << i;
    }
  }
  k = 1;
  bool o = false;
  while (l > 0) {
    if (l & 1) {
      if (o) x -= k;
      else o = true;
      edges.push_back({1, j, x});
    }
    k *= 2;
    j--;
    l >>= 1;
  }
  cout << n << " " << edges.size() << endl;
  for (auto z:edges) {
    int u, v, c;
    tie(u, v, c) = z;
    cout << u << " " << v << " " << c << endl;
  }
}
