// https://open.kattis.com/problems/armystrengtheasy
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int ng, nm, mg, mm;
        cin >> ng >> nm;
        ng--; nm--;
        cin >> mg;
        while (ng--) {
            int x;
            cin >> x;
            mg = max(mg, x);
        }
        cin >> mm;
        while (nm--) {
            int x;
            cin >> x;
            mm = max(mm, x);
        }
        if (mm > mg) cout << "MechaGodzilla\n";
        else cout << "Godzilla\n";
    }
}