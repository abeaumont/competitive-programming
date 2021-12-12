#!/usr/bin/env pike
int count = 0, start, end;
mapping(int:multiset(int)) graph = ([]);
mapping(int:int) big = ([]);
multiset(int) set = (<>);

void dfs(int u) {
  if (u == end) {
    count++;
    return;
  }
  set[u] = true;
  foreach (graph[u]; int k; int v) {
    if (big[k] || !set[k])
      dfs(k);
  }
  set[u] = false;
}

int main() {
  mapping(string:int) names = ([]);
  int i = 1;
  while (string s = Stdio.stdin.gets()) {
    array(string) xs = s / "-";
    int u = names[xs[0]];
    if (u == 0) {
      names[xs[0]] = i++;
      u = names[xs[0]];
      graph[u] = (<>);
      big[u] = xs[0][0] < 'a';
      if (xs[0] == "start") start = u;
      else if (xs[0] == "end") end = u;
    }
    int v = names[xs[1]];
    if (v == 0) {
      names[xs[1]] = i++;
      v = names[xs[1]];
      graph[v] = (<>);
      big[v] = xs[1][0] < 'a';
      if (xs[1] == "start") start = v;
      else if (xs[1] == "end") end = v;
    }
    graph[u][v] = true;
    graph[v][u] = true;
  }
  dfs(start);
  write("%d\n", count);
}
