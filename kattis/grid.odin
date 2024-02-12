// https://open.kattis.com/problems/grid
package main

import "core:c/libc"
import "core:container/queue"
import "core:fmt"

main :: proc() {
	n, m : int
	libc.scanf("%d %d\n", &n, &m)
	g := make([][]int, n)
	used := make([][]bool, n)
	for i in 0..<n {
		g[i] = make([]int, m)
		used[i] = make([]bool, m)
		for j in 0..<m {
			libc.scanf("%c", &g[i][j])
			g[i][j] -= '0'
		}
		libc.scanf("\n")
	}
	q : queue.Queue([3]int)
	queue.init(&q)
	queue.push_back(&q, [3]int{0, 0, 0})
	for queue.len(q) > 0 {
		xs := queue.pop_front(&q)
		k, y, x := xs[0], xs[1], xs[2]
		if y == n - 1 && x == m - 1 {
			fmt.println(k)
			return
		}
		for d in ([4][2]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
			ny := y + d[0] * g[y][x]
			nx := x + d[1] * g[y][x]
			if ny >= 0 && ny < n && nx >= 0 && nx < m && !used[ny][nx] {
				used[ny][nx] = true
				queue.push_back(&q, [3]int{k+1, ny, nx})
			}
		}
	}
	fmt.println(-1)
}
