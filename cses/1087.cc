// https://cses.fi/problemset/task/1087/
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
  string s, t;
  cin >> s;
  unordered_set<char> cs;
  for (auto c : s) {
    cs.insert(c);
    if (cs.size() == 4) {
      t.push_back(c);
      cs.clear();
    }
  }
  if (!cs.count('A')) t.push_back('A');
  else if (!cs.count('C')) t.push_back('C');
  else if (!cs.count('G')) t.push_back('G');
  else t.push_back('T');
  cout << t << endl;
}
