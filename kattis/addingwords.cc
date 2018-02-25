// https://open.kattis.com/problems/addingwords
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

typedef unordered_map<string, int> msi;
typedef unordered_map<int, string> mis;


int main() {
    msi a;
    mis b;
    string l;
    while (getline(cin, l)) {
        stringstream in(l);
        string c;
        in >> c;
        if (c == "def") {
            string n;
            int v;
            in >> n >> v;
            if (a.find(n) != a.end()) b.erase(a[n]);
            a[n] = v;
            b[v] = n;
        } else if (c == "calc") {
            int r = 0;
            bool result = true;
            string n;
            in >> n;
            if (a.find(n) == a.end()) result = false;
            else r = a[n];
            cout << n << " ";
            while (true) {
                in >> n;
                cout << n << " ";
                if (n == "=") break;
                bool plus = n == "+";
                in >> n;
                cout << n << " ";
                if (a.find(n) == a.end()) result = false;
                else if (plus) r += a[n];
                else r -= a[n];
            }
            if (!result || b.find(r) == b.end()) cout << "unknown\n";
            else cout << b[r] << endl;
        } else if (c == "clear") {
            a.clear();
            b.clear();
        }
    }
}