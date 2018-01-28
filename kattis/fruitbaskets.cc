// https://open.kattis.com/problems/fruitbaskets
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll c;

void subsets(const vi& v, vi& set, int i, int sum) {
  if (set.size() == 4 || i == v.size()) {
    if (sum < 200) c += sum;
    return;
  }
  set.push_back(i);
  subsets(v, set, i + 1, sum + v[i]);
  set.pop_back();
  subsets(v, set, i + 1, sum);
}

int main() {
  int n;
  cin >> n;
  vi v(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  vi set;
  subsets(v, set, 0, 0);
  sum *= 1LL << (n - 1);
  sum -= c;
  cout << sum << endl;
}
