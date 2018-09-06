// https://codeforces.com/contest/1038/problem/B
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int N = 45000;
bool primes[N+1];

int main() {
  ll n, s;
  cin >> n;
  s = n * (n + 1) / 2;
  for (int i = 2; i <= N; i++) primes[i]=true;
  for (int i = 2; i*i <= N; i++)
    if (primes[i])
      for (int j = i*2; j <= N; j+=i) primes[j]=false;
  for (int i = 1; i * i <= s; i++) {
    if (primes[i] && s % i == 0) {
      if (s == primes[i]) {
        cout << "No\n";
        return 0;
      }
      cout << "Yes\n";
      ll a = i;
      ll b = s - a;
      vi c;
      vi d;
      for (int j = n; j > 0; j--) {
        if (a >= j) {
          c.push_back(j);
          a -= j;
        } else {
          d.push_back(j);
          b -= j;
        }
      }
      cout << c.size() << " ";
      for (int i = 0; i < c.size(); i++) {
        cout << c[i];
        if (i < c.size() - 1) cout << " ";
      }
      cout << endl;
      cout << d.size() << " ";
      for (int i = 0; i < d.size(); i++) {
        cout << d[i];
        if (i < d.size() - 1) cout << " ";
      }
      cout << endl;
      return 0;
    }
  }
  cout << "No\n";
}
