// https://open.kattis.com/problems/calories
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    while (true) {
        string a[5];
        int m[5] = {9, 4, 4, 4, 7};
        cin >> a[0];
        if (a[0] == "-") break;
        double tf = 0;
        double tt = 0;
        while (true) {
            for (int i = 1; i < 5; i++) cin >> a[i];
            bool fp = false;
            int f = 0;
            int c = 0;
            int p = 0;
            for (int i = 0; i < 5; i++) {
                switch (a[i][a[i].size() - 1]) {
                case 'g':
                    c += m[i] * atoi(a[i].c_str());
                    if (!i) f = c;
                    break;
                case 'C':
                    c += atoi(a[i].c_str());
                    if (!i) f = c;
                    break;
                default:
                    p += atoi(a[i].c_str());
                    if (!i) {
                        f = p;
                        fp = true;
                    }
                }
            }
            double t = double(c) * 100 / (100 - p);
            if (fp) tf += t * f / 100;
            else tf += f;
            tt += t;
            cin >> a[0];
            if (a[0] == "-") break;
        }
        cout << round(tf * 100 / tt) << "%\n";
    }
}