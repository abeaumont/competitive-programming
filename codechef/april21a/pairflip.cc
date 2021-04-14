// https://www.codechef.com/APRIL21A/problems/PAIRFLIP
#include <bits/stdc++.h>

using namespace std;

struct graph {
  int n;
  vector<vector<int>> g;
  vector<int> nodes;
};

struct op {
  char type;
  int k, i, j;
};

vector<vector<int>> g, h;
vector<int> visited;
int cc;

void dfs(int u) {
  visited[u] = cc;
  for (int v : g[u])
    if (!visited[v]) dfs(v);
}

vector<pair<pair<int, int>, pair<int, int>>> sols;

int dfs2(int u) {
  int x = -1;
  for (int v : h[u])
    if (visited[v]) {
      if (visited[v] > visited[u]) {
        if (x >= 0) sols.push_back({{u, v}, {u, x}}), x = -1;
        else
          x = v;
      }
    } else {
      visited[v] = visited[u] + 1;
      int y = dfs2(v);
      if (y >= 0) sols.push_back({{u, v}, {v, y}});
      else if (x >= 0)
        sols.push_back({{u, v}, {u, x}}), x = -1;
      else
        x = v;
    }
  return x;
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n, m, e;
  cin >> t;
  while (t--) {
    cin >> n >> m >> e;
    vector<string> A(n), B(n);
    g = vector<vector<int>>(n + m);
    int edges = 0;
    vector<pair<int, int>> ps;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (B[i][j] == '?') ps.push_back({i, n + j});
        else if (A[i][j] != B[i][j])
          edges++, g[i].push_back(n + j), g[n + j].push_back(i);
    if (edges % 2 && ps.empty()) {
      cout << "-1\n";
      continue;
    }
    visited = vector<int>(n + m);
    cc = 0;
    for (int i = 0; i < n + m; i++)
      if (!visited[i]) cc++, dfs(i);
    vector<int> count(cc);
    vector<graph> gs(cc);
    for (int i = 0; i < n + m; i++) {
      count[visited[i] - 1] += g[i].size();
      gs[visited[i] - 1].nodes.push_back(i);
    }
    for (int i = 0; i < cc; i++) count[i] /= 2;
    for (int i = 0; i < ps.size(); i++) {
      int u, v;
      tie(u, v) = ps[i];
      int c = visited[u] - 1;
      if (count[c] % 2) gs[c].nodes.push_back(n + m + i), count[c]++;
      c = visited[v] - 1;
      if (count[c] % 2) gs[c].nodes.push_back(n + m + i), count[c]++;
    }
    int oddedges = 0;
    for (int i = 0; i < cc; i++) oddedges += count[i] % 2;
    if (oddedges % 2)
      for (int i = 0; i < cc; i++)
        if (gs[i].nodes.back() >= n + m) {
          count[i]--;
          gs[i].nodes.pop_back();
          break;
        }
    vector<int> ni(n + m);
    vector<pair<int, int>> pending;
    vector<op> ans;
    for (int i = 0; i < cc; i++) {
      unordered_set<int> used;
      for (int j = 0; j < gs[i].nodes.size(); j++)
        if (gs[i].nodes[j] < n + m) {
          used.insert(gs[i].nodes[j]);
          ni[gs[i].nodes[j]] = j;
        } else {
          int u = gs[i].nodes[j] - n - m;
          if (!used.count(ps[u].first)) {
            ni[ps[u].first] = j;
            gs[i].nodes.push_back(ps[u].first);
            swap(gs[i].nodes[j], gs[i].nodes.back());
            used.insert(ps[u].first);
            j++;
          }
          if (!used.count(ps[u].second)) {
            ni[ps[u].second] = j;
            gs[i].nodes.push_back(ps[u].second);
            swap(gs[i].nodes[j], gs[i].nodes.back());
            used.insert(ps[u].second);
            j++;
          }
          break;
        }
      h = vector<vector<int>>(gs[i].nodes.size());
      visited = vector<int>(gs[i].nodes.size());
      for (int u : gs[i].nodes) {
        if (u < n + m)
          for (int v : g[u]) {
            if (used.count(v)) h[ni[u]].push_back(ni[v]);
          }
        else {
          u -= n + m;
          h[ni[ps[u].first]].push_back(ni[ps[u].second]);
          h[ni[ps[u].second]].push_back(ni[ps[u].first]);
        }
      }
      sols.clear();
      visited[0] = 1;
      int x = dfs2(0);
      if (x >= 0) pending.push_back({gs[i].nodes[0], gs[i].nodes[x]});
      for (auto sol : sols) {
        auto f = sol.first, s = sol.second;
        int a, b, c;
        if (f.first == s.first) a = f.first, b = f.second, c = s.second;
        else if (f.first == s.second)
          a = f.first, b = f.second, c = s.first;
        else if (f.second == s.first)
          a = f.second, b = f.first, c = s.second;
        else if (f.second == s.second)
          a = f.second, b = f.first, c = s.first;
        else
          assert(0);
        a = gs[i].nodes[a], b = gs[i].nodes[b], c = gs[i].nodes[c];
        ans.push_back(op{"RC"[a >= n], a >= n ? a - n : a, b >= n ? b - n : b,
                         c >= n ? c - n : c});
      }
    }
    if (ps.empty() && pending.size() % 2) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < pending.size() - pending.size() % 2; i += 2) {
      auto x = pending[i], y = pending[i + 1];
      ans.push_back(op{'R', x.first, x.second - n, y.second - n});
      ans.push_back(op{'C', y.second - n, x.first, y.first});
    }
    if (pending.size() % 2) {
      auto x = pending.back(), y = ps[0];
      ans.push_back(op{'R', x.first, x.second - n, y.second - n});
      ans.push_back(op{'C', y.second - n, x.first, y.first});
    }
    cout << ans.size() << '\n';
    if (e)
      for (op o : ans)
        cout << o.type << ' ' << o.k + 1 << ' ' << o.i + 1 << ' ' << o.j + 1
             << '\n';
  }
}
