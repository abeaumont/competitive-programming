// https://open.kattis.com/problems/segmentintersection
#include <bits/stdc++.h>

using namespace std;

struct p {
  double x, y;
  p(double x, double y) : x(x), y(y) {}
  p operator+(p p) { return {x + p.x, y + p.y}; }
  p operator-(p p) { return {x - p.x, y - p.y}; }
  p operator*(double s) { return {s * x, s * y}; }
  p operator/(double s) { return {x / s, y / s}; }
  double operator*(p p) { return x * p.x + y * p.y; }
  double operator^(p p) { return x * p.y - y * p.x; }
  bool operator<(p p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(p p) { return tie(x, y) == tie(p.x, p.y); }
  bool operator>(p p) { return !(*this < p || *this == p); }
  friend ostream &operator<<(ostream &os, p p) {
    os << double(p.x) << " " << double(p.y);
    return os;
  }
};

void f(p p1, p p2, p p3, p p4) {
  p s1 = p2 - p1, s2 = p4 - p3;
  double a = s1 ^ s2, a1 = s1 ^ (p3 - p1), a2 = s2 ^ (p3 - p1);
  if (p1 == p2) {
    if (p3 == p4) {
      if (p1 == p3) cout << p1 << "\n";
      else
        cout << "none\n";
    } else
      f(p3, p4, p1, p2);
  } else if (!(s1 ^ s2)) {
    double b1 = p1 * s1, c1 = p2 * s1, b2 = p3 * s1, c2 = p4 * s1;
    cout << s1 << " " << s2 << endl;
    cout << a1 << " " << a2 << " " << b1 << " " << c1 << " " << b2 << " " << c2
         << endl;
    if (a1 || a2 || max(b1, min(b2, c2)) > min(c1, max(b2, c2)))
      cout << "none\n";
    else {
      p r1 = min(b2, c2) < b1 ? p1 : (b2 < c2 ? p3 : p4),
        r2 = max(b2, c2) > c1 ? p2 : (b2 > c2 ? p3 : p4);
      if (r1 == r2) cout << r1 << "\n";
      else
        cout << min(r1, r2) << " " << max(r1, r2) << "\n";
    }
  } else {
    if (a < 0) a = -a, a1 = -a1, a2 = -a2;
    if (a1 > 0 || a < -a1 || a2 > 0 || a < -a2) cout << "none\n";
    else
      cout << p1 - s1 * a2 / a << "\n";
  }
}

int main() {
  int n;
  cin >> n;
  cout << setprecision(2) << fixed;
  while (n--) {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    p p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
    f(p1, p2, p3, p4);
  }
}
