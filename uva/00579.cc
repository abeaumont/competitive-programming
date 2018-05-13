// https://uva.onlinejudge.org/external/5/579.pdf
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	while (true) {
		int h, m;
		scanf("%d:%d\n", &h, &m);
		if (!h && !m) break;
		double ha = h * 30 + m * 0.5;
		if (ha >= 360) ha -= 360;
		int ma = m * 6;
		double da = abs(ha - ma);
		printf("%.3f\n", min(da, 360 - da));
	}
}
