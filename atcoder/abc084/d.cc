// https://abc084.contest.atcoder.jp/tasks/abc084_d
#include <iostream>

using namespace std;

const int N = 100000;
bool primes[N+1];
int similar[N+1];

int main() {
  for (int i = 2; i <= N; i++) primes[i]=true;
  for (int i = 2; i*i <= N; i++)
    if (primes[i])
      for (int j = i*2; j <= N; j+=i) primes[j]=false;
  for (int i = 1; i <= N; i++)
    if (primes[i] && primes[(i+1)/2]) similar[i]++;
  for (int i = 1; i <= N; i++)
    similar[i] += similar[i-1];
  int q, l, r;
  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << similar[r] - similar[l-1] << endl;
  }
}
