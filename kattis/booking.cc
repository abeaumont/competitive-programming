// https://open.kattis.com/problems/booking
#include <algorithm>
#include <cstdio>
#include <vector>


#include <iostream>
using namespace std;

typedef vector<int> vi;

int d2i(int y, int m, int d, int h, int M) {
    int k = (y - 2013) * 365 * 24 * 60;
    int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y == 2016) md[2]++;
    for (int i = 1; i < 13; i++) md[i] += md[i - 1];
    d += md[m - 1];
    return k + d * 24 * 60 + h * 60 + M;
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int b, c;
        scanf("%d %d\n", &b, &c);
        vi in(b);
        vi out(b);
        for (int i = 0; i < b; i++) {
            char id[21];
            int y1, m1, d1, h1, M1, y2, m2, d2, h2, M2;
            scanf("%s %d-%d-%d %d:%d %d-%d-%d %d:%d\n", id, &y1, &m1, &d1, &h1, &M1, &y2, &m2, &d2, &h2, &M2);
            in[i] = d2i(y1, m1, d1, h1, M1);
            out[i] = d2i(y2, m2, d2, h2, M2);
        }
        sort(in.begin(), in.end());
        sort(out.begin(), out.end());
        int i = 0, j = 0, k = 0, m = 0;
        while (i < b) {
            if (out[j] + c <= in[i]) {
                j++;
                k--;
            } else {
                i++;
                k++;
                m = max(m, k);
            }
        }
        printf("%d\n", m);
    }
}