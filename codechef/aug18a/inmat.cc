// https://www.codechef.com/AUG18A/problems/INMAT
#include <iostream>
#include <tuple>

using namespace std;

typedef tuple<int, int> ii;

int n, k, v, r[1000], c[1000], r0[1000], r1[1000], c0[1000], c1[1000];

ii f1(int i, int j) {
  int x, y, z;
  y = j;
  x = n;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = j;
  x = 1;
  while (y > i && x <= n) {
    if (y == j && x == n) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x++;
    else y--;
  }
  return {-1, -1};
}

ii f2(int i, int j) {
  int x, y, z;
  y = i + 1;
  x = n;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = i + 1;
  x = 1;
  while (y <= j && x <= n) {
    if (y == i + 1 && x == n) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x++;
    else y++;
  }
  return {-1, -1};
}

ii f3(int i, int j) {
  int x, y, z;
  y = j;
  x = 1;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = j;
  x = n;
  while (y > i && x > 0) {
    if (y == j && x == 1) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x--;
    else y--;
  }
  return {-1, -1};
}

ii f4(int i, int j) {
  int x, y, z;
  y = i + 1;
  x = 1;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = i + 1;
  x = n;
  while (y <= j && x > 0) {
    if (y == i + 1 && x == 1) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x--;
    else y++;
  }
  return {-1, -1};
}

ii f5(int i, int j) {
  int x, y, z;
  y = n;
  x = j;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = 1;
  x = j;
  while (y <= n && x > i) {
    if (y == n && x == j) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) y++;
    else x--;
  }
  return {-1, -1};
}

ii f6(int i, int j) {
  int x, y, z;
  y = n;
  x = i + 1;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = 1;
  x = i + 1;
  while (y <= n && x <= j) {
    if (y == n && x == i + 1) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) y++;
    else x++;
  }
  return {-1, -1};
}

ii f7(int i, int j) {
  int x, y, z;
  y = 1;
  x = j;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = n;
  x = j;
  while (y > 0 && x > i) {
    if (y == 1 && x == j) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) y--;
    else x--;
  }
  return {-1, -1};
}

ii f8(int i, int j) {
  int x, y, z;
  y = 1;
  x = i + 1;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = n;
  x = i + 1;
  while (y > 0 && x <= j) {
    if (y == 1 && x == i + 1) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) y--;
    else x++;
  }
  return {-1, -1};
}

ii cr() {
  int o = r[0], k = 0, y, x;
  for (int i = 0; i < n; i++) {
    if (r[i] != o) {
      if (!c[0] && v < r0[i] || c[0] && v > r0[i]) {
        if (!o && !c[0]) {
          tie(y, x) = f1(k, i);
          if (y == -1) {
            k = i;
            while (i < n && o != r[i]) i++;
            return f3(k, i);
          }
          return {y, x};
        }
        if (!o) {
          tie(y, x) = f2(k, i);
          if (y == -1) {
            k = i;
            while (i < n && o != r[i]) i++;
            return f4(k, i);
          }
          return {y, x};
        }
        if (!c[0]) {
          tie(y, x) = f3(k, i);
          if (y == -1) {
            k = i;
            while (i < n && o != r[i]) i++;
            return f1(k, i);
          }
          return {y, x};
        }
        tie(y, x) = f4(k, i);
        if (y == -1) {
          k = i;
          while (i < n && o != r[i]) i++;
          return f2(k, i);
        }
        return {y, x};
      }
      k = i;
      o = r[i];
    }
  }
  if (!o && !c[0]) return f1(k, n);
  if (!o) return f2(k, n);
  if (!c[0]) return f3(k, n);
  return f4(k, n);
}

ii cc() {
  int o = c[0], k = 0, y, x;
  for (int i = 0; i < n; i++) {
    if (c[i] != o) {
      if (!r[0] && v < c0[i] || r[0] && v > c0[i]) {
        if (!o && !r[0]) {
          tie(y, x) = f5(k, i);
          if (y == -1) {
            k = i;
            while (i < n && o != c[i]) i++;
            return f7(k, i);
          }
          return {y, x};
        }
        if (!o) {
          tie(y, x) = f6(k, i);
          if (y == -1) {
            k = i;
            while (i < n && o != c[i]) i++;
            return f8(k, i);
          }
          return {y, x};
        }
        if (!r[0]) {
          tie(y, x) = f7(k, i);
          if (y == -1) {
            k = i;
            while (i < n && o != c[i]) i++;
            return f5(k, i);
          }
          return {y, x};
        }
        tie(y, x) = f8(k, i);
        if (y == -1) {
          k = i;
          while (i < n && o != c[i]) i++;
          return f6(k, i);
        }
        return {y, x};
      }
      o = c[i];
      k = i;
    }
  }
  if (!o && !r[0]) return f5(k, n);
  if (!o) return f6(k, n);
  if (!r[0]) return f7(k, n);
  return f8(k, n);
}

ii g1(int xi, int xj, int yi, int yj) {
  int x, y, z;
  y = yj;
  x = xj;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = yj;
  x = xi + 1;
  while (y > yi && x <= xj) {
    if (y == yj && x == xj) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x++;
    else y--;
  }
  return {-1, -1};
}

ii g2(int xi, int xj, int yi, int yj) {
  int x, y, z;
  y = yi + 1;
  x = xj;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = yi + 1;
  x = xi + 1;
  while (y <= yj && x <= xj) {
    if (y == yi + 1 && x == xj) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x++;
    else y++;
  }
  return {-1, -1};
}

ii g3(int xi, int xj, int yi, int yj) {
  int x, y, z;
  y = yj;
  x = xi + 1;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = yj;
  x = xj;
  while (y > yi && x > xi) {
    if (y == yj && x == xi + 1) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x--;
    else y--;
  }
  return {-1, -1};
}

ii g4(int xi, int xj, int yi, int yj) {
  int x, y, z;
  y = yi + 1;
  x = xi + 1;
  cout << "1 " << y << " " << x << endl;
  cin >> z;
  if (v == z) return {y, x};
  if (v > z) return {-1, -1};
  y = yi + 1;
  x = xj;
  while (y <= yj && x > xi) {
    if (y == yi + 1 && x == xi + 1) break;
    cout << "1 " << y << " " << x << endl;
    cin >> z;
    if (v == z) return {y, x};
    if (v > z) x--;
    else y++;
  }
  return {-1, -1};
}

ii all(int sy, int sx) {
  int y, x;
  if (!c[0]) {
    tie(y, x) = g1(0, n - sx, 0, n - sy);
    if (y == -1) tie(y, x) = g2(n - sx, n, 0, n - sy);
    if (y == -1) tie(y, x) = g3(0, n - sx, n - sy, n);
    if (y == -1) tie(y, x) = g4(n - sx, n, n - sy, n);
  } else {
    tie(y, x) = g4(0, sx, 0, sy);
    if (y == -1) tie(y, x) = g3(sx, n, 0, sy);
    if (y == -1) tie(y, x) = g2(0, sx, sy, n);
    if (y == -1) tie(y, x) = g1(sx, n, sy, n);
  }
  return {y, x};
}

int main() {
  cin >> n >> k >> v;
  if (k >= n * n) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        int x;
        cout << "1 " << i << " " << j << endl;
        cin >> x;
        if (x == v) {
          cout << "2 " << i << " " << j << endl;
          return 0;
        }
      }
    cout << "2 -1 -1\n";
    return 0;
  }
  
  int p = 0;
  int z = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cout << "1 " << i + 1 << " " << i + 1 << endl;
    cin >> x;
    r0[i] = x;
    c1[i] = x;
    if (!i) z = x;
    if (p && p > x) c[i] = 1;
    p = x;
    cout << "1 " << i + 1 << " " << (i + 1) % n + 1 << endl;
    cin >> x;
    if (i != n - 1 && p > x) r[i] = 1;
    else if (i == n - 1 && p < x) r[i] = 1;
    r1[i] = x;
    c0[(i + 1) % n] = x;
    p = x;
  }
  if (z > p) c[0] = 1;
  int sx = 0, sy = 0;
  for (int i = 0; i < n; i++) if (r[i]) sy++;
  for (int i = 0; i < n; i++) if (c[i]) sx++;
  int y = 0, x = 0;
  if (!sy && !sx) tie(y, x) = f1(0, n);
  else if (!sy && sx == n) tie(y, x) = f2(0, n);
  else if (sy == n && !sx) tie(y, x) = f3(0, n);
  else if (sy == n && sx == n) tie(y, x) = f4(0, n);
  else if (sy && sy != n && sx && sx != n) tie(y, x) = all(sy, sx);
  else if (sy && sy != n) tie(y, x) = cr();
  else tie(y, x) = cc();
  cout << "2 " << y << " " << x << endl;
}
