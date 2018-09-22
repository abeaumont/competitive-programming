// https://www.codechef.com/SEPT18A/problems/PHOTOCOM
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
ll t, n, h1, w1, h2, w2;
string s1, s2;
vvi m;

void f() {
  m = vvi(h2, vi(w2));
  m[0][0] = s2[0] == '1';
  for (int i = 1; i < w2; i++) m[0][i] = m[0][i-1] + (s2[i] == '1');
  for (int i = 1; i < h2; i++) {
    ll c = 0;
    for (int j = 0; j < w2; j++) {
      ll a = s2[i*w2+j] == '1';
      m[i][j] = c + m[i-1][j] + a;
      c += a;
    }
  }
}

ll r(int y1, int y2, int x1, int x2) {
  if (y1==0 && x1==0) return m[y2][x2];
  if (y1==0) return m[y2][x2]-m[y2][x1-1];
  if (x1==0) return m[y2][x2]-m[y1-1][x2];
  return m[y2][x2]-m[y2][x1-1]-m[y1-1][x2]+m[y1-1][x1-1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> h1 >> w1 >> s1 >> h2 >> w2 >> s2;
    if (h1*w1>h2*w2) {
      swap(h1,h2);
      swap(w1,w2);
      swap(s1,s2);
    }
    f();
    ll h = __gcd(h1, h2);
    ll w = __gcd(w1, w2);
    h = h1*h2/h;
    w = w1*w2/w;
    ll h1m = h/h1, h2m = h/h2, w1m = w/w1, w2m = w/w2;
    ll s = 0;
    for (int i = 0; i < h1; i++)
      for (int j = 0; j < w1; j++) {
        ll y1 = i*h1m, y2 = (i+1)*h1m,
          x1 = j*w1m, x2 = (j+1)*w1m,
          cy1 = (y1+h2m-1)/h2m,
          cy2 = (y2+h2m-1)/h2m,
          cx1 = (x1+w2m-1)/w2m,
          cx2 = (x2+w2m-1)/w2m,
          fy1 = y1/h2m,
          fy2 = y2/h2m,
          fx1 = x1/w2m,
          fx2 = x2/w2m,
          c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0,
          k, a;
        if (fy2 > cy1 && fx2 > cx1) {
          k = r(cy1,fy2-1,cx1,fx2-1);
          a = (fy2-cy1)*(fx2-cx1);
          if (s1[i*w1+j] == '1') c0 = k;
          else c0 = a-k;
          c0 *= h2m*w2m;
        }
        if (fy1 == fy2) {
          if (fx2 > cx1) {
            k = r(fy1,fy1,cx1,fx2-1);
            a = fx2-cx1;
            if (s1[i*w1+j] == '1') c1=k;
            else c1=a-k;
            c1 *= (y2-y1)*w2m;
          }
        } else if (fx2 > cx1) {
          if (fy1 != cy1) {
            k = r(fy1,fy1,cx1,fx2-1);
            a = fx2-cx1;
            if (s1[i*w1+j] == '1') c1=k;
            else c1=a-k;
            c1 *= w2m*(cy1*h2m-y1);
          }
          if (fy2 != cy2) {
            k = r(fy2,fy2,cx1,fx2-1);
            a = fx2-cx1;
            if (s1[i*w1+j] == '1') c2=k;
            else c2=a-k;
            c2 *= w2m*(y2-fy2*h2m);
          }
        }
        if (fx1 == fx2) {
          if (fy2 > cy1) {
            k = r(cy1,fy2-1,fx1,fx1);
            a = fy2-cy1;
            if (s1[i*w1+j] == '1') c3=k;
            else c3=a-k;
            c3 *= h2m*(x2-x1);
          }
        } else if (fy2 > cy1) {
          if (fx1 != cx1) {
            k = r(cy1,fy2-1,fx1,fx1);
            a = fy2-cy1;
            if (s1[i*w1+j] == '1') c3=k;
            else c3=a-k;
            c3 *= h2m*(cx1*w2m-x1);
          }
          if (fx2 != cx2) {
            k = r(cy1,fy2-1,fx2,fx2);
            a = fy2-cy1;
            if (s1[i*w1+j] == '1') c4=k;
            else c4=a-k;
            c4 *= h2m*(x2-fx2*w2m);
          }
        }
        if (fx1 == fx2 && fy1 == fy2) {
          if (fx1 != cx2 && fy1 != cy2)
            if (s2[fy1*w2+fx1] == s1[i*w1+j]) c5 += (x2-x1)*(y2-y1);
        } else if (fx1 == fx2) {
          if (fx1 != cx2 && fy1 != cy1) {
            if (s2[fy1*w2+fx1] == s1[i*w1+j]) c5 += (x2-x1)*(cy1*h2m-y1);
          }
          if (fx1 != cx2 && fy2 != cy2)
            if (s2[fy2*w2+fx2] == s1[i*w1+j]) c7 += (x2-x1)*(y2-fy2*h2m);
        } else if (fy1 == fy2) {
          if (fx1 != cx1 && fy1 != cy2) {
            if (s2[fy1*w2+fx1] == s1[i*w1+j]) c5 += (cx1*w2m-x1)*(y2-y1);
          }
          if (fx2 != cx2 && fy1 != cy2) {
            if (s2[fy1*w2+fx2] == s1[i*w1+j]) c6 += (x2-fx2*w2m)*(y2-y1);
          }
        } else {
          if (fx1 != cx1 && fy1 != cy1) {
            if (s2[fy1*w2+fx1] == s1[i*w1+j]) c5 += (cx1*w2m-x1)*(cy1*h2m-y1);
          }
          if (fx2 != cx2 && fy1 != cy1) {
            if (s2[fy1*w2+fx2] == s1[i*w1+j]) c6 += (x2-fx2*w2m)*(cy1*h2m-y1);
          }
          if (fx2 != cx2 && fy2 != cy2) {
            if (s2[fy2*w2+fx2] == s1[i*w1+j]) c7 += (x2-fx2*w2m)*(y2-fy2*h2m);
          }
          if (fx1 != cx1 && fy2 != cy2)
            if (s2[fy2*w2+fx1] == s1[i*w1+j]) c8 += (cx1*w2m-x1)*(y2-fy2*h2m);
        }
        s += c0+c1+c2+c3+c4+c5+c6+c7+c8;
      }
    cout << s << endl;
  }
}
