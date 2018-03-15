// https://open.kattis.com/problems/vauvau
#include <iostream>

using namespace std;

void s(int k) {
    if (!k) cout << "none\n";
    else if (k == 1) cout << "one\n";
    else cout << "both\n";
}

int main() {
    int a, b, c, d, e, f, p, m, g;
    cin >> a >> b >> c >> d >> p >> m >> g;
    int x[3] = {p, m, g};
    e = a + b;
    f = c + d;
    for (int i = 0; i < 3; i++) {
        int k = 0;
        if (x[i] % e && x[i] % e <= a) k++;
        if (x[i] % f && x[i] % f <= c) k++;
        s(k);
    }
}