// https://www.codechef.com/MAY20A/problems/NBOTS
#include <bits/stdc++.h>

using namespace std;

using ci = tuple<char, int>;
using ici = tuple<int, char, int>;
using iici = tuple<int, int, char, int>;
using sici = set<ici>;
using siici = set<iici>;
using vi = vector<int>;
using vvi = vector<vi>;
using vci = vector<ci>;
using vici = vector<ici>;
using viici = vector<iici>;

const int L = 0, R = 1, U = 2, D = 3;

int n, f, k;
vvi t;
default_random_engine generator;
vci r;

void solve_greedy_randomness() {
  uniform_int_distribution<int> dis(1, 1000000000);
  vvi cache(4, vi(n));
  vvi rnd(4, vi(n));
  vvi left(4, vi(n));
  vvi right(4, vi(n, n-1));
  siici q;
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = left[L][i]; j < n; j++) {
      if (s + t[i][j] > f) {
        cache[L][i] = s;
        right[L][i] = j-1;
        break;
      } else s += t[i][j];
      if (s && !t[i][left[L][i]]) left[L][i] = j;
    }
    if (!cache[L][i]) {
      cache[L][i] = s;
      if (s) right[L][i] = n-1;
      else right[L][i] = n;
    }
    if (cache[L][i]) {
      rnd[L][i] = dis(generator);
      q.insert({-cache[L][i], rnd[L][i], 'L', i});
    }
  }
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = right[R][i]; j >= 0; j--) {
      if (s + t[i][j] > f) {
        cache[R][i] = s;
        left[R][i] = j+1;
        break;
      } else s += t[i][j];
      if (s && !t[i][right[R][i]]) right[R][i] = j;
    }
    if (!cache[R][i]) {
      cache[R][i] = s;
      if (s) left[R][i] = 0;
      else left[R][i] = n;
    }
    if (cache[R][i]) {
      rnd[R][i] = dis(generator);
      q.insert({-cache[R][i], rnd[R][i], 'R', i});
    }
  }
  for (int j = 0; j < n; j++) {
    int s = 0;
    for (int i = left[U][j]; i < n; i++) {
      if (s + t[i][j] > f) {
        cache[U][j] = s;
        right[U][j] = i-1;
        break;
      } else s += t[i][j];
      if (s && !t[left[U][j]][j]) left[U][j] = i;
    }
    if (!cache[U][j]) {
      cache[U][j] = s;
      if (s) right[U][j] = n-1;
      else right[U][j] = n;
    }
    if (cache[U][j]) {
      rnd[U][j] = dis(generator);
      q.insert({-cache[U][j], rnd[U][j], 'U', j});
    }
  }
  for (int j = 0; j < n; j++) {
    int s = 0;
    for (int i = right[D][j]; i >= 0; i--) {
      if (s + t[i][j] > f) {
        cache[D][j] = s;
        left[D][j] = i+1;
        break;
      } else s += t[i][j];
      if (s && !t[right[D][j]][j]) right[D][j] = i;
    }
    if (!cache[D][j]) {
      cache[D][j] = s;
      if (s) left[D][j] = 0;
      else left[D][j] = n;
    }
    if (cache[D][j]) {
      rnd[D][j] = dis(generator);
      q.insert({-cache[D][j], rnd[D][j], 'D', j});
    }
  }
  while (!q.empty()) {
    auto it = q.begin();
    int w, v, x, y;
    tie(w, v, x, y) = *it;
    r.push_back({x, y+1});
    viici invalid;
    if (x == 'L') {
      int s = 0;
      invalid.emplace_back(-cache[L][y], rnd[L][y], 'L', y);
      if (right[L][y] >= left[R][y]) invalid.emplace_back(-cache[R][y], rnd[R][y], 'R', y);
      for (int j = 0; j < n; j++) {
        if (s + t[y][j] > f) break;
        else s += t[y][j];
        if (left[U][j] <= y && right[U][j] >= y-1) invalid.emplace_back(-cache[U][j], rnd[U][j], 'U', j);
        if (left[D][j] <= y+1 && right[D][j] >= y) invalid.emplace_back(-cache[D][j], rnd[D][j], 'D', j);
        t[y][j] = 0;
      }
    } else if (x == 'R') {
      int s = 0;
      invalid.emplace_back(-cache[R][y], rnd[R][y], 'R', y);
      if (left[R][y] <= right[L][y]) invalid.emplace_back(-cache[L][y], rnd[L][y], 'L', y);
      for (int j = n-1; j >= 0; j--) {
        if (s + t[y][j] > f) break;
        else s += t[y][j];
        if (left[U][j] <= y && right[U][j] >= y-1) invalid.emplace_back(-cache[U][j], rnd[U][j], 'U', j);
        if (left[D][j] <= y+1 && right[D][j] >= y) invalid.emplace_back(-cache[D][j], rnd[D][j], 'D', j);
        t[y][j] = 0;
      }
    } else if (x == 'U') {
      int s = 0;
      invalid.emplace_back(-cache[U][y], rnd[U][y], 'U', y);
      if (right[D][y] >= left[D][y]) invalid.emplace_back(-cache[D][y], rnd[D][y], 'D', y);
      for (int i = 0; i < n; i++) {
        if (s + t[i][y] > f) break;
        else s += t[i][y];
        if (left[L][i] <= y && right[L][i] >= y-1) invalid.emplace_back(-cache[L][i], rnd[L][i], 'L', i);
        if (left[R][i] <= y+1 && right[R][i] >= y) invalid.emplace_back(-cache[R][i], rnd[R][i], 'R', i);
        t[i][y] = 0;
      }
    } else if (x == 'D') {
      int s = 0;
      invalid.emplace_back(-cache[D][y], rnd[D][y], 'D', y);
      if (left[D][y] <= right[U][y]) invalid.emplace_back(-cache[U][y], rnd[U][y], 'U', y);
      for (int i = n-1; i >= 0; i--) {
        if (s + t[i][y] > f) break;
        else s += t[i][y];
        if (left[L][i] <= y && right[L][i] >= y-1) invalid.emplace_back(-cache[L][i], rnd[L][i], 'L', i);
        if (left[R][i] <= y+1 && right[R][i] >= y) invalid.emplace_back(-cache[R][i], rnd[R][i], 'R', i);
        t[i][y] = 0;
      }
    } else assert(false);

    for (auto z : invalid) {
      q.erase(z);
      tie(w, v, x, y) = z;
      if (x == 'L') {
        int i = y;
        int s = 0;
        cache[L][i] = 0;
        for (int j = left[L][i]; j < n; j++) {
          if (s + t[i][j] > f) {
            cache[L][i] = s;
            right[L][i] = j-1;
            break;
          } else s += t[i][j];
          if (s && !t[i][left[L][i]]) left[L][i] = j;
        }
        if (!cache[L][i]) {
          cache[L][i] = s;
          if (s) right[L][i] = n-1;
          else right[L][i] = n;
        }
        if (cache[L][i]) {
          rnd[L][i] = dis(generator);
          q.insert({-cache[L][i], rnd[L][i], 'L', i});
        }
      } else if (x == 'R') {
        int i = y;
        int s = 0;
        cache[R][i] = 0;
        for (int j = right[R][i]; j >= 0; j--) {
          if (s + t[i][j] > f) {
            cache[R][i] = s;
            left[R][i] = j+1;
            break;
          } else s += t[i][j];
          if (s && !t[i][right[R][i]]) right[R][i] = j;
        }
        if (!cache[R][i]) {
          cache[R][i] = s;
          if (s) left[R][i] = 0;
          else left[R][i] = n;
        }
        if (cache[R][i]) {
          rnd[R][i] = dis(generator);
          q.insert({-cache[R][i], rnd[R][i], 'R', i});
        }
      } else if (x == 'U') {
        int j = y;
        int s = 0;
        cache[U][j] = 0;
        for (int i = left[U][j]; i < n; i++) {
          if (s + t[i][j] > f) {
            cache[U][j] = s;
            right[U][j] = i-1;
            break;
          } else s += t[i][j];
          if (s && !t[left[U][j]][j]) left[U][j] = i;
        }
        if (!cache[U][j]) {
          cache[U][j] = s;
          if (s) right[U][j] = n-1;
          else right[U][j] = n;
        }
        if (cache[U][j]) {
          rnd[U][j] = dis(generator);
          q.insert({-cache[U][j], rnd[U][j], 'U', j});
        }
      } else if (x == 'D') {
        int j = y;
        int s = 0;
        cache[D][j] = 0;
        for (int i = right[D][j]; i >= 0; i--) {
          if (s + t[i][j] > f) {
            cache[D][j] = s;
            left[D][j] = i+1;
            break;
          } else s += t[i][j];
          if (s && !t[right[D][j]][j]) right[D][j] = i;
        }
        if (!cache[D][j]) {
          cache[D][j] = s;
          if (s) left[D][j] = 0;
          else left[D][j] = n;
        }
        if (cache[D][j]) {
          rnd[D][j] = dis(generator);
          q.insert({-cache[D][j], rnd[D][j], 'D', j});
        }
      } else assert(false);
    }
  }
}


void read() {
  cin.tie(0), ios::sync_with_stdio(0);
  cin >> n >> f;
  t = vvi(n, vi(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> t[i][j];
  cin >> k;
}

void generate(int l, int r) {
  uniform_int_distribution<int> dis(l, r);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      t[i][j] = dis(generator);
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    if (argc > 2) generator.seed(atoi(argv[2]));
    else generator.seed(chrono::steady_clock::now().time_since_epoch().count());
    n = f = 512;
    t = vvi(n, vi(n));
    int l[] = {1, 1, 1, 1, f/4, f/4, f/4, f/2, f/2};
    int r[] = {f/4, f/2, 3*f/4, f, f/2, 3*f/4, f, 3*f/4, f};
    int tc = atoi(argv[1]);
    generate(l[tc], r[tc]);
  } else {
    generator.seed(chrono::steady_clock::now().time_since_epoch().count());
    read();
  }
  solve_greedy_randomness();
  cout << r.size() << '\n';
  if (argc <= 1)
    for (ci x : r)
      cout << get<0>(x) << ' ' << get<1>(x) << '\n';
}  
