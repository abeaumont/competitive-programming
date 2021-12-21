int64[] count(int start) {
	var rounds = new int64[20];
	var dp = new int64[2,21,10];
	int64[] freqs = {1, 3, 6, 7, 6, 3, 1};
	dp[0,0,start] = 1;
	for (int i = 1; i < 21; i++) {
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 10; k++)
				dp[i%2,j,k] = 0;
		for (int j = 0; j < 21; j++)
			for (int k = 0; k < 10; k++)
				for (int l = 3; l < 10; l++) {
					int x = (k + l) % 10;
					int64 v = dp[(i%2)^1,j,k] * freqs[l-3];
					if (j+x+1 >= 21) rounds[i] += v;
					else dp[i%2,j+x+1,x] += v;
				}
		if (i > 3 && rounds[i] == 0) break;
	}
	return rounds;
}

void main() {
	var xs = stdin.read_line().split(" ");
	var r0 = count(int.parse(xs[xs.length - 1]) - 1);
	xs = stdin.read_line().split(" ");
	var r1 = count(int.parse(xs[xs.length - 1]) - 1);
	var p0 = new int64[20], p1 = new int64[20];
	p0[0] = p1[0] = 1;
	for (int i = 0; i < 19; i++) {
		p0[i+1] = (p0[i] - r0[i]) * 27;
		p1[i+1] = (p1[i] - r1[i]) * 27;
	}
	int64[] sums = {0, 0};
	for (int i = 1; i < 20; i++) {
		sums[0] += r0[i] * (p1[i-1]-r1[i-1]);
		sums[1] += r1[i] * (p0[i]-r0[i]);
	}
	stdout.printf("%lld\n", sums[0] > sums[1] ? sums[0] : sums[1]);
}
