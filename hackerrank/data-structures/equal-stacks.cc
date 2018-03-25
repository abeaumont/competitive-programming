// https://www.hackerrank.com/challenges/equal-stacks
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef stack<int> si;
typedef vector<int> vi;

int main() {
	int n1, n2, n3;
	si s1, s2, s3;
	cin >> n1 >> n2 >> n3;
	vi v1(n1), v2(n2), v3(n3);
	for (int i = 0; i < n1; i++) cin >> v1[i];
	for (int i = 0; i < n2; i++) cin >> v2[i];
	for (int i = 0; i < n3; i++) cin >> v3[i];
	int sum = 0;
	for (int i = n1 - 1; i >= 0; i--) {
		sum += v1[i];
		s1.push(sum);
	}
	sum = 0;
	for (int i = n2 - 1; i >= 0; i--) {
		sum += v2[i];
		s2.push(sum);
	}
	sum = 0;
	for (int i = n3 - 1; i >= 0; i--) {
		sum += v3[i];
		s3.push(sum);
	}
	while (true) {
		if (s1.empty() || s2.empty() || s3.empty()) {
			cout << 0 << endl;
			break;
		}
		n1 = s1.top();
		n2 = s2.top();
		n3 = s3.top();
		if (n1 == n2 && n2 == n3) {
			cout << n1 << endl;
			break;
		}
		if (n1 >= n2 && n1 >= n3) {
			s1.pop();
			continue;
		}
		if (n2 >= n1 && n2 >= n3) {
			s2.pop();
			continue;
		}
		s3.pop();
	}
}
