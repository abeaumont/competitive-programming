// https://www.hackerrank.com/challenges/correctness-invariant/submissions/code/1178010
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

void insertionSort(vi &a) {
	int i, j, k;
	for(i = 1; i< a.size(); i++) {
		k = a[i];
		j = i - 1;
		while (j >= 0 && k < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
	for(auto k : a) cout << k << " ";
}

int main() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	insertionSort(a);
}
