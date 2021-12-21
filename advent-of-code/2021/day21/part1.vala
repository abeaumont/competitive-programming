void main() {
	var start = new int[2];
	int[] sums = {0, 0};
	for (int i = 0; i < 2; i++) {
		var xs = stdin.read_line().split(" ");
		start[i] = int.parse(xs[xs.length - 1]) - 1;
	}
	int i = 0;
	while (true) {
		for (int j = 0; j < 2; j++) {
			start[j] = (start[j] + 3*i + 6) % 10;
			sums[j] += start[j] + 1;
			i += 3;
			if (sums[j] >= 1000) {
				stdout.printf("%d\n", sums[j^1] * i);
				return;
			}
		}
	}
}
