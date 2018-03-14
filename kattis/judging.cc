// https://open.kattis.com/problems/judging
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef unordered_map<string, int> msi;
typedef unordered_set<string> ss;

int main() {
    int n;
    cin >> n;
    msi a;
    msi b;
    ss c;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c.insert(s);
        a[s]++;
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        c.insert(s);
        b[s]++;
    }
    int t = 0;
    for (auto s : c) t += min(a[s], b[s]);
    cout << t << endl;
}