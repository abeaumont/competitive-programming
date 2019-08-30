// https://cses.fi/problemset/task/1162
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef set<int> si;
typedef vector<int> vi;

ll f1(vi a) {
  ll z = 0;
  function<vi (vi)> f = [&](vi a)->vi {
    if (a.size() == 1) return a;
    int s = a.size() / 2;
    vi b(a.begin(), a.begin() + s);
    b = f(b);
    vi c(a.begin() + s, a.end());
    c = f(c);
    int i = 0;
    int j = 0;
    while (i < b.size() && j < c.size()) {
      if (b[i] < c[j]) {
        a[i+j] = b[i];
        i++;
      } else {
        a[i+j] = c[j];
        j++;
        z += s - i;
      }
    }
    while (i < b.size()) {
      a[i+j] = b[i];
      i++;
    }
    while (j < c.size()) {
      a[i+j] = c[j];
      j++;
    }
    return a;
  };
  f(a);
  return z;
}

ll f2(vi a) {
  int n = a.size();
  vi b(n);
  for (int i = 0; i < n; i++) b[a[i]] = i;
  ll z = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == i) continue;
    ll s = b[i];
    ll t = i;
    b[a[i]] = s;
    swap(a[s], a[t]);
    z++;
  }
  return z;
}

ll f3(vi a) {
  si s;
  for (auto z:a) {
    s.insert(z);
    auto it = s.find(z); it++;
    if (it != s.end()) s.erase(it);
  }
  return a.size() - s.size();
}

ll f4(vi a) {
  int n = a.size();
  int k = n - 1;
  for (int i = n - 1; i >= 0; i--)
    if (a[i] == k) k--;
  return k + 1;
}

int main() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  cout << f1(a) << " " << f2(a) << " " << f3(a) << " " << f4(a) << endl;
}
