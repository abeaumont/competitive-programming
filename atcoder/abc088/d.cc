// https://abc088.contest.atcoder.jp/tasks/abc088_d
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef tuple<int, int> ii;
typedef tuple<int, int, int> iii;
typedef unordered_set<ii> sii;
typedef priority_queue<iii> pq;

namespace std {
  template<> struct hash<ii> {
    size_t operator()(const ii &i) const {
      return hash<int>()(get<0>(i) * 100 + get<1>(i));
    };
  };
}

int s(const vvb &m, int h, int w, sii &v, pq &q) {
	int k, i, j;
	while (true) {
		if (q.empty()) return -1;
		tie(k, i, j) = q.top();
		k = -k;
		q.pop();
		if (v.count(make_tuple(i, j))) continue;
		v.insert(make_tuple(i, j));
		break;
	}
	if (i == h - 1 && j == w - 1) return k;
	if (i > 0 && m[i - 1][j] && !v.count(make_tuple(i - 1, j))) q.push(make_tuple(-(k + 1), i - 1, j));
	if (i < h - 1 && m[i + 1][j] && !v.count(make_tuple(i + 1, j))) q.push(make_tuple(-(k + 1), i + 1, j));
	if (j > 0 && m[i][j - 1] && !v.count(make_tuple(i, j - 1))) q.push(make_tuple(-(k + 1), i, j - 1));
	if (j < w - 1 && m[i][j + 1] && !v.count(make_tuple(i, j + 1))) q.push(make_tuple(-(k + 1), i, j + 1));
	return s(m, h, w, v, q);
}

int main() {
	int h, w;
	cin >> h >> w;
	vvb m(h);
	int b = 0;
	for (int i = 0; i < h; i++) {
		m[i] = vb(w);
		for (int j = 0; j < w; j++) {
			char c;
			cin >> c;
			m[i][j] = c == '.';
			b += c == '#';
		}
	}
	pq q;
	q.push(make_tuple(-1, 0, 0));
	sii v;
	int c = s(m, h, w, v, q);
	if (c == -1) cout << -1 << endl;
	else cout << h * w - c - b << endl;
}
