// https://open.kattis.com/problems/hidden
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string p, m;
    cin >> p >> m;
    unordered_multiset<char> s;
    for (auto c : p) s.insert(c);
    int i = 0;
    bool ok = true;
    for (auto c : m) {
        auto it = s.find(c);
        if (it != s.end()) {
            if (p[i] != c) {
                ok = false;
                break;
            }
            s.erase(it);
            i++;
        }
    }
    ok = ok && s.empty();
    cout << (ok ? "PASS\n" : "FAIL\n");
}