// https://open.kattis.com/problems/erraticants
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tuple<int, int>> vii;
typedef unordered_map<int, int> miii;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int x = 0;
    int y = 0;
    int c = 0;
    int p = c;
    miii nodes;
    vii edges;
    nodes[x * 100 + y] = c++;
    cin >> n;
    for (int i = 0; i < n; i++) {
      char d;
      cin >> d;
      switch (d) {
      case 'S': y--; break;
      case 'N': y++; break;
      case 'W': x--; break;
      case 'E': x++; break;
      }
      auto it = nodes.find(x * 100 + y);
      if (it == nodes.end()) {
        nodes[x * 100 + y] = c;
        edges.push_back(make_tuple(p, c));
        p = c++;
      } else {
        edges.push_back(make_tuple(p, it->second));
        p = it->second;
      }
    }
    vvi distance(c);
    for (int i = 0; i < c; i++) {
      distance[i] = vi(c, 100);
      distance[i][i] = 0;
    }
    for (auto e : edges) {
      int a, b;
      tie(a, b) = e;
      distance[a][b] = 1;
      distance[b][a] = 1;
    }
    for (int k = 0; k < c; k++)
      for (int i = 0; i < c; i++)
        for (int j = 0; j < c; j++)
          distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
    cout << distance[0][p] << endl;
  }
}
