// https://open.kattis.com/problems/vectorfunctions
#include <vector>
using namespace std;

void backwards(vector<int> &vec) {
  for (int i = 0; i < vec.size() / 2; i++)
    swap(vec[i], vec[vec.size() - i - 1]);
}

vector<int> everyOther(const vector<int> &vec) {
  vector<int> x;
  for (int i = 0; i < vec.size(); i += 2) x.push_back(vec[i]);
  return x;
}

int smallest(const vector<int> &vec) {
  int s = vec[0];
  for (int x : vec) s = min(s, x);
  return s;
}

int sum(const vector<int> &vec) {
  int s = 0;
  for (int x : vec) s += x;
  return s;
}

int veryOdd(const vector<int> &vec) {
  int c = 0;
  for (int i = 1; i < vec.size(); i += 2) c += vec[i] % 2 != 0;
  return c;
}
