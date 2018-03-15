// https://www.codechef.com/COOK87/problems/CK87GSUB
#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int i = 0;
        int j = i + 1;
        ll c = 0;
        while (j < n) {
            while (j < n && s[j] == s[i]) j++;
            ll d = j - i;
            c += d * (d - 1) / 2;
            if (i > 0 && s[j] == s[i - 1]) c++;
            i = j;
        }
        cout << c << endl;
    }
}