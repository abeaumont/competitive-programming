// https://open.kattis.com/problems/patuljci
#include <bits/stdc++.h>

using namespace std;

const int N = 9;
int x[N];

int main() {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    sum += x[i];
  }

  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++)
      if (sum - x[i] - x[j] == 100)
        for (int k = 0; k < N; k++)
          if (k != i && k != j) cout << x[k] << endl;
}
