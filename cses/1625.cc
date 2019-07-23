// https://cses.fi/problemset/task/1625
#include <bits/stdc++.h>

using namespace std;

string s;
int g[7][7];

int f(int y, int x, int i, char m) {
  if (i == 48) return 1;
  if (g[6][0]) return 0;
  if (m == 'L' && (x == 0 || g[y][x-1]) && y > 0 && y < 6 && !g[y-1][x] && !g[y+1][x]) return 0;
  if (m == 'R' && (x == 6 || g[y][x+1]) && y > 0 && y < 6 && !g[y-1][x] && !g[y+1][x]) return 0;
  if (m == 'U' && (y == 0 || g[y-1][x]) && x > 0 && x < 6 && !g[y][x-1] && !g[y][x+1]) return 0;
  if (m == 'D' && (y == 6 || g[y+1][x]) && x > 0 && x < 6 && !g[y][x-1] && !g[y][x+1]) return 0;
  if (s[i] == '?') {
    int r[] = {-1, 0, 1, 0};
    int c[] = {0, -1, 0, 1};
    int k = 0;
    for (int j = 0; j < 4; j++) {
      int yy = y + r[j];
      int xx = x + c[j];
      if (yy < 0 || yy > 6) continue;
      if (xx < 0 || xx > 6) continue;
      if (g[yy][xx]) continue;
      g[yy][xx] = true;
      k += f(yy, xx, i + 1, "ULDR"[j]);
      g[yy][xx] = false;
    }
    return k;
  }
  if (s[i] == 'L') x--;
  else if (s[i] == 'R') x++;
  else if (s[i] == 'U') y--;
  else if (s[i] == 'D') y++;
  if (x < 0 || x > 6) return 0;
  if (y < 0 || y > 6) return 0;
  if (g[y][x]) return 0;
  g[y][x] = true;
  int k = f(y, x, i + 1, s[i]);
  g[y][x] = false;
  return k;
}


int main() {
  cin >> s;
  g[0][0] = true;
  cout << f(0, 0, 0, 0) << endl;
}
