// https://codeforces.com/contest/1042/problem/B
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000;
ll n, d[N], dp[N+1][7], INF=1000000000000LL;
bool a[N], b[N], c[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> d[i] >> s;
    for (char ch:s)
      if (ch=='A') a[i]=true;
      else if (ch=='B') b[i]=true;
      else if (ch=='C') c[i]=true;
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 7; j++) dp[i][j] = INF;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 7; j++) dp[i][j] = dp[i-1][j];
    if (a[i-1]&&b[i-1]&&c[i-1])
      for (int j = 0; j < 7; j++) dp[i][j] = min(dp[i][j], d[i-1]);
    else if (a[i-1]&&b[i-1]) {
      dp[i][0] = min(dp[i][0], d[i-1]);
      dp[i][1] = min(dp[i][1], d[i-1]);
      dp[i][3] = min(dp[i][3], d[i-1]);
      dp[i][4] = min(dp[i][4], dp[i][2]+d[i-1]);
      dp[i][6] = min(dp[i][6], dp[i][2]+d[i-1]);
    } else if (a[i-1]&&c[i-1]) {
      dp[i][0] = min(dp[i][0], d[i-1]);
      dp[i][2] = min(dp[i][2], d[i-1]);
      dp[i][4] = min(dp[i][4], d[i-1]);
      dp[i][3] = min(dp[i][3], dp[i][1]+d[i-1]);
      dp[i][6] = min(dp[i][6], dp[i][1]+d[i-1]);
    } else if (b[i-1]&&c[i-1]) {
      dp[i][1] = min(dp[i][1], d[i-1]);
      dp[i][2] = min(dp[i][2], d[i-1]);
      dp[i][5] = min(dp[i][5], d[i-1]);
      dp[i][3] = min(dp[i][3], dp[i][0]+d[i-1]);
      dp[i][6] = min(dp[i][6], dp[i][0]+d[i-1]);
    } else if (a[i-1]) {
      dp[i][0] = min(dp[i][0], d[i-1]);
      dp[i][3] = min(dp[i][3], dp[i][1]+d[i-1]);
      dp[i][4] = min(dp[i][4], dp[i][2]+d[i-1]);
      dp[i][6] = min(dp[i][6], dp[i][5]+d[i-1]);
    } else if (b[i-1]) {
      dp[i][1] = min(dp[i][1], d[i-1]);
      dp[i][3] = min(dp[i][3], dp[i][0]+d[i-1]);
      dp[i][5] = min(dp[i][5], dp[i][2]+d[i-1]);
      dp[i][6] = min(dp[i][6], dp[i][4]+d[i-1]);
    } else if (c[i-1]) {
      dp[i][2] = min(dp[i][2], d[i-1]);
      dp[i][4] = min(dp[i][4], dp[i][0]+d[i-1]);
      dp[i][5] = min(dp[i][6], dp[i][1]+d[i-1]);
      dp[i][6] = min(dp[i][6], dp[i][3]+d[i-1]);
    }
  }
  cout << (dp[n][6] == INF? -1:dp[n][6]) << endl;
}
