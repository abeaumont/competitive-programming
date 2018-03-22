// https://www.hackerrank.com/challenges/mini-max-sum
#include <stdio.h>

int main() {
    long long a[5];
    scanf("%lld %lld %lld %lld %lld", &a[0], &a[1], &a[2], &a[3], &a[4]);
    long long min = a[0];
    long long max = a[0];
    long long sum = a[0];
    for (int i = 1; i < 5; i++) {
        if (min > a[i]) min = a[i];
        if (max < a[i]) max = a[i];
        sum += a[i];
    }
    printf("%lld %lld\n", sum - max, sum - min);
    return 0;
}
