// https://www.hackerrank.com/challenges/simple-array-sum
#include <stdio.h>

int main() {
	int n, x, s = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d\n", &x);
		s += x;
	}
	printf("%d\n", s);
}
