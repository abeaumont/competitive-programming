#include <iostream>

using namespace std;

int main() {
    int k, n, s = 0;
    cin >> k >> n;
    bool ok = true;
    while (n-- && ok) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > s) ok = false;
        s -= a;
        if (s + b > k) ok = false;
        s += b;
        if (c && s < k) ok = false;
        if (!n && (c || s)) ok = false;
    }
    cout << (ok ? "possible\n" : "impossible\n");
}