// https://www.codechef.com/MARCH20A/problems/EGGFREE
#include <bits/stdc++.h>

using namespace std;
using ii = tuple<int, int>;
using si = set<int>;
using vi = vector<int>;
using vsi = vector<si>;
using vii = vector<ii>;
using vvii = vector<vii>;

struct part {
  int i;
  si vertices;
};

int n, m;
vi order, inv;
vsi g;
vii edges;
list<part> parts;
vector<list<part>::iterator> pointers;

void update_vertex(int u, int i) {
  for (int v : g[u]) {
    auto it = pointers[v];
    if (it == parts.begin()) {
      part p = {i, si()};
      it = parts.insert(it, p);
    } else {
      it--;
      if (it->i != i) {
        it++;
        part p = {i, si()};
        it = parts.insert(it, p);
      }
    }
    pointers[v]->vertices.erase(v);
    if (pointers[v]->vertices.empty())
      parts.erase(pointers[v]);
    it->vertices.insert(v);
    pointers[v] = it;
    g[v].erase(u);
  }
  g[u].clear();
  pointers[u]->vertices.erase(u);
  if (pointers[u]->vertices.empty())
    parts.erase(pointers[u]);
}

bool is_chordal() {
  vvii g(n);
  for (int i=0; i<m; i++) {
    int u, v;
    tie(u, v) = edges[i];
    g[u].push_back({inv[v], v});
    g[v].push_back({inv[u], u});
  }
  for (int i=0;i<n;i++)
    sort(g[i].begin(), g[i].end());
  for (int u : order) {
    // find closest neighbor prior to u
    ii f = {inv[u], 0};
    auto it = lower_bound(g[u].begin(), g[u].end(), f);
    if (it == g[u].begin()) continue;
    it--;
    if (it == g[u].end()) continue;
    int v, k;
    tie(k, v) = *it;
    // check all the earlier neighs
    for (auto it2 = g[u].begin(); it2 != it; it2++)
      if (!binary_search(g[v].begin(), g[v].end(), *it2))
        return 0;
  }
  return 1;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, u, v;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    g = vsi(n);
    edges = vii(m);
    for (int i=0; i<m; i++) {
      cin >> u >> v, u--, v--;
      edges[i] = {u,v};
      g[u].insert(v);
      g[v].insert(u);
    }
    parts = list<part>(1);
    pointers = vector<list<part>::iterator>(n);
    auto it = parts.begin();
    for (int i=0; i<n; i++) {
      it->vertices.insert(i);
      pointers[i] = it;
    }
    order = vi(n), inv = vi(n);
    for (int i=1; !parts.empty(); i++) {
      it = parts.begin();
      int u = *(it->vertices.begin());
      update_vertex(u, i);
      order[i-1] = u;
    }
    for (int i=0; i<n; i++)
      inv[order[i]]=i;
    if (!is_chordal()) cout << "No solution\n";
    else {
      string r(m, ' ');
      for (int i=0; i<m; i++) {
        tie(u, v) = edges[i];
        if (inv[u] < inv[v]) r[i] = 'v';
        else r[i] = '^';
      }
      cout << r << endl;
    }
  }
}
