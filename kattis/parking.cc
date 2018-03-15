// https://open.kattis.com/problems/parking
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int a, b, c, s[3], e[3];
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) cin >> s[i] >> e[i];
    sort(s, s+3);
    sort(e, e+3);
    int t = 0, d = 0, i = 0, j = 0, p = 0;
    while (i < 3) {
        if (s[i] <= e[j]) {
            switch (d) {
            case 0: break;
            case 1:
                t += (s[i] - p) * a;
                break;
            case 2:
                t += (s[i] - p) * b * 2;
                break;
            default:
                t += (s[i] - p) * c * 3;
            }
            p = s[i];
            d++;
            i++;
        } else {
            switch (d) {
            case 1:
                t += (e[j] - p) * a;
                break;
            case 2:
                t += (e[j] - p) * b * 2;
                break;
            default:
                t += (e[j] - p) * c * 3;
            }
            d--;
            p = e[j];
            j++;
        }
    }
    while (j < 3) {
        switch (d) {
        case 1:
            t += (e[j] - p) * a;
            break;
        case 2:
            t += (e[j] - p) * b * 2;
            break;
        default:
            t += (e[j] - p) * c * 3;
        }
        d--;
        p = e[j];
        j++;
    }
    cout << t << endl;
}