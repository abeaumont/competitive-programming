// https://open.kattis.com/problems/virtualfriends
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef unordered_map<string, int> msi;

int find(vi &l, int x) {
    while(x != l[x]) x = l[x];
    return x;
}

void unite(vi &l, vi& s, int a, int b) {
    a = find(l, a);
    b = find(l, b);
    if (a == b) return;
    if (s[a] < s[b]) swap(a, b);
    s[a] += s[b];
    l[b] = a;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi l(2 * n), s(2 * n);
        for (int i = 0; i < 2 * n; i++) l[i] = i;
        for (int i = 0; i < 2 * n; i++) s[i] = 1;
        int c = 0;
        msi m;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            int a, b;
            if (m.find(s1) == m.end()) {
                a = c++;
                m[s1] = a;
            } else a = m[s1];
            if (m.find(s2) == m.end()) {
                b = c++;
                m[s2] = b;
            } else b = m[s2];
            unite(l, s, a, b);
            cout << s[find(l, a)] << endl;
        }
    }
}