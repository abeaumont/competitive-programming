// https://open.kattis.com/problems/jabuke
#include <bits/stdc++.h>

using namespace std;

template <class T>
struct point {
  typedef point pt;
  T x, y;
  point(T x, T y) : x(x), y(y) {}
  pt operator+(pt p) { return pt(x+p.x, y+p.y); }
  pt operator-(pt p) { return pt(x-p.x, y-p.y); }
  pt operator&(T d) { return pt(x*d, y*d); }
  pt operator/(T d) { return pt(x/d, y/d); }
  T operator*(pt p) { return x*p.x + y*p.y; }
  T operator^(pt p) { return x*p.y - y*p.x; }
  double operator~() { return sqrt(sq()); }
  T sq() { return x*x + y*y; }
  friend ostream& operator<<(ostream &os, pt p) { return os << '(' << p.x << ',' << p.y << ')'; }
};
using pt = point<int>;

int main() {
  int n, c = 0, x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  pt p(x1, y1), q(x2, y2), r(x3, y3);
  pt pq = q - p, pr = r - p, rp = p - r, rq = q - r;
  if ((pq ^ pr) < 0) swap(pq, pr);
  if ((rp ^ rq) < 0) swap(rp, rq);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> y1;
    pt x = pt(x1, y1);
    pt px = x - p, rx = x - r;
    c += ((pq ^ px) >= 0 && (pr ^ px) <= 0 && (rp ^ rx) >= 0 && (rq ^ rx) <= 0);
  }
  printf("%.1f\n%d\n", (pq ^ pr) / 2.0, c);
}
