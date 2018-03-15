#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool is = true, iq = true, ipq = true;
        while (n--) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                s.push(b);
                q.push(b);
                pq.push(b);
            } else {
                if (s.empty()) {
                    is = false;
                    iq = false;
                    ipq = false;
                } else {
                    if (s.top() != b) is = false;
                    if (q.front() != b) iq = false;
                    if (pq.top() != b) ipq = false;
                    s.pop();
                    q.pop();
                    pq.pop();
                }
            }
        }
        int c = 0;
        if (is) c++;
        if (iq) c++;
        if (ipq) c++;
        switch (c) {
        case 0: cout << "impossible\n"; break;
        case 1:
            if (is) cout << "stack\n";
            else if (iq) cout << "queue\n";
            else cout << "priority queue\n";
            break;
        default:
            cout << "not sure\n";
        }
    }
}
