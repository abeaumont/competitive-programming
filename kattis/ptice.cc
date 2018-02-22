// https://open.kattis.com/problems/ptice
#include <iostream>

using namespace std;

int main() {
	string s1 = "ABC";
	string s2 = "BABC";
	string s3 = "CCAABB";
	int k;
	cin >> k;
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < k; i++) if (s[i] == s1[i%s1.size()]) a++;
	for (int i = 0; i < k; i++) if (s[i] == s2[i%s2.size()]) b++;
	for (int i = 0; i < k; i++) if (s[i] == s3[i%s3.size()]) c++;
	int m = max(a, max(b, c));
	cout << m << endl;
	if (a == m) cout << "Adrian\n";
	if (b == m) cout << "Bruno\n";
	if (c == m) cout << "Goran\n";
}
