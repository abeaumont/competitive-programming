// https://open.kattis.com/problems/piglatin
#include <iostream>

using namespace std;

int main() {
  string s;
  while (true) {
    getline(cin, s);
    if (s.empty()) break;
    int begin = -1;
    int vowel = -1;
    for (int i = 0; i <= s.size(); i++) {
      if (i == s.size() || isspace(s[i])) {
        if (begin == -1) continue;
        cout << s.substr(vowel, i - vowel) << s.substr(begin, vowel - begin)
             << (begin == vowel ? "yay" : "ay")
             << (i == s.size() ? "\n" : " ");
        begin = vowel = -1;
      } else {
        if (begin == -1) begin = i;
        if (vowel == -1
            && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y'))
          vowel = i;
      }
    }
  }
}
