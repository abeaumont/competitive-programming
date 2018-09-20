// https://codeforces.com/contest/1042/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 200000;
ll n, m, z, a[N];
bool b[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i]) z++;
    else if (a[i]<0) m++;
  }
  if (m%2&&z) {
    ll M = -100000000000LL;
    int k;
    int zi;
    for (int i = 0; i < n; i++) {
      if (a[i]==0) zi=i;
      else if (a[i]<0 && a[i] >M) {
        M = a[i];
        k = i;
      }
    }
    printf("1 %d %d\n", k+1, zi+1);
    b[k]=true;
    if (z > 1) {
      for (int i = 0; i < n; i++) {
        if (i == zi) continue;
        if (a[i]==0) {
          printf("1 %d %d\n", i+1, zi+1);
          b[i]=true;
        }
      }
    }
    if (z < n - 1) {
      printf("2 %d\n", zi+1);
      b[zi] = true;
    }
  } else if (m%2) {
    ll M = -100000000000LL;
    int k;
    for (int i = 0; i < n; i++) {
      if (a[i]<0 && a[i]>M) {
        M = a[i];
        k = i;
      }
    }
    b[k]=true;
    printf("2 %d\n", k+1);
  } else if (z) {
    int zi;
    for (int i = 0; i < n; i++) if (!a[i]) {zi=i; break;}
    if (z>1) {
      for (int i = zi+1; i < n; i++) if (!a[i]) {
          b[i]=true;
          printf("1 %d %d\n", i+1, zi+1);
        }
    }
    if (z < n) {
      printf("2 %d\n", zi+1);
      b[zi]=true;
    }
  }
  int i = 0;
  for (;i<n;i++) if (!b[i]) break;
  for (int j = i+1; j<n;j++) if (!b[j]) printf("1 %d %d\n", j+1, i+1);
}
