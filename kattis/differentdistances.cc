// https://open.kattis.com/problems/differentdistances
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    while (true) {
        double x1, y1, x2, y2, p;
        cin >> x1;
        if (!x1) break;
        cin >> y1 >> x2 >> y2 >> p;
        cout << pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1 / p) << endl;
    }
}