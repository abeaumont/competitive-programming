// https://cses.fi/problemset/info/1145/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main() {
    int n, x;
    cin >> n;
    vi a;
    while (n--) {
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        if (it == a.end()) a.push_back(x);
        else *it = x;
    }
    cout << a.size() << endl;
}