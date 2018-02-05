// https://www.codechef.com/FEB18/problems/PERMPAL
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef unordered_map<char, int> mci;
typedef unordered_map<char, vi> mcvi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    mcvi p;
    mci f;
    for (int i = 0; i < n; i++) {
      p[s[i]].push_back(i + 1);
      f[s[i]]++;
    }
    int odd = 0;
    for (auto x : f) odd += x.second % 2;
    if (odd > n % 2) {
      cout << "-1\n";
      continue;
    }
    vi a(n);
    int i = 0;
    for (auto pr : p) {
      vi &v = pr.second;
      for (int j = 0; j < v.size(); j++) {
        if (j == v.size() - 1) a[n / 2] = v[j];
        else {
          a[i++] = v[j++];
          a[a.size() - i] = v[j];
        }
      }
    }
    for (i = 0; i < n; i++) {
      cout << a[i];
      if (i < n - 1) cout << " ";
      else cout << endl;
    }
  }
}
