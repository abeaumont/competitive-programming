// https://open.kattis.com/problems/ecoins
#include <bits/stdc++.h>

using namespace std;

const int N = 300, INF = 10000000, T = 47;

int triples[T][3] = {
    {3, 4, 5},       {5, 12, 13},     {8, 15, 17},     {7, 24, 25},
    {20, 21, 29},    {12, 35, 37},    {9, 40, 41},     {28, 45, 53},
    {11, 60, 61},    {16, 63, 65},    {33, 56, 65},    {48, 55, 73},
    {13, 84, 85},    {36, 77, 85},    {39, 80, 89},    {65, 72, 97},
    {20, 99, 101},   {60, 91, 109},   {15, 112, 113},  {44, 117, 125},
    {88, 105, 137},  {17, 144, 145},  {24, 143, 145},  {51, 140, 149},
    {85, 132, 157},  {119, 120, 169}, {52, 165, 173},  {19, 180, 181},
    {57, 176, 185},  {104, 153, 185}, {95, 168, 193},  {28, 195, 197},
    {84, 187, 205},  {133, 156, 205}, {21, 220, 221},  {140, 171, 221},
    {60, 221, 229},  {105, 208, 233}, {120, 209, 241}, {32, 255, 257},
    {23, 264, 265},  {96, 247, 265},  {69, 260, 269},  {115, 252, 277},
    {160, 231, 281}, {161, 240, 289}, {68, 285, 293}};

int dp[N + 1][N + 1];

int solve(vector<pair<int, int>> &x, int a, int b) {
  for (int i = 0; i <= a; i++)
    for (int j = 0; j <= b; j++) dp[i][j] = INF;
  dp[0][0] = 0;
  for (auto [p, q] : x) {
    for (int i = 0; i <= a - p; i++)
      for (int j = 0; j <= b - q; j++)
        if (dp[i][j] < INF)
          dp[i + p][j + q] = min(dp[i + p][j + q], dp[i][j] + 1);
  }
  return dp[a][b];
}

int main() {
  cin.tie(0), ios::sync_with_stdio();
  int n, m, s;
  cin >> n;
  while (n--) {
    cin >> m >> s;
    vector<pair<int, int>> x(m);
    for (int i = 0; i < m; i++) cin >> x[i].first >> x[i].second;
    vector<pair<int, int>> cs = {{0, s}, {s, 0}};
    for (int i = 0; i < 47; i++) {
      if (s % triples[i][2] == 0) {
        int d = s / triples[i][2];
        cs.push_back({triples[i][0] * d, triples[i][1] * d});
        cs.push_back({triples[i][1] * d, triples[i][0] * d});
      }
    }
    int ans = INF;
    for (auto [a, b] : cs) ans = min(ans, solve(x, a, b));
    if (ans == INF) cout << "not possible\n";
    else
      cout << ans << '\n';
  }
}
