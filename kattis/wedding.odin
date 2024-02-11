// https://open.kattis.com/problems/wedding
package main

import "core:c/libc"
import "core:fmt"
import "core:slice"

Pair :: struct {
	fst, snd : int
}

n : int
g, gi : [][dynamic]int
used, ans : []bool
order : [dynamic]int
ccs : []int

dfs1 :: proc(u: int) {
	used[u] = true
	for v in g[u] {
		if !used[v] do dfs1(v)
	}
	append(&order, u)
}

dfs2 :: proc(u, cc: int) {
	ccs[u] = cc
	for v in gi[u] {
		if ccs[v] < 0 do dfs2(v, cc)
	}
}

twosat :: proc(pairs: []Pair) -> bool {
	g = make([][dynamic]int, n)
	gi = make([][dynamic]int, n)
	for p in pairs {
		append(&g[p.fst~1], p.snd)
		append(&g[p.snd~1], p.fst)
		append(&gi[p.snd], p.fst~1)
		append(&gi[p.fst], p.snd~1)
	}

	used = make([]bool, n)
	for u in 0..<n {
		if !used[u] do dfs1(u)
	}

	ccs = make([]int, n)
	slice.fill(ccs, -1)
	cc := 0
	for i := n-1; i >= 0; i -= 1 {
		u := order[i]
		if ccs[u] < 0 {
			dfs2(u, cc)
			cc += 1
		}
	}

	ans = make([]bool, n/2)
	for i := 0; i < n; i += 2 {
		if ccs[i] == ccs[i+1] do return false
		ans[i/2] = ccs[i] > ccs[i+1]
	}
	return true
}

main :: proc() {
	k, m : int
	libc.scanf("%d %d", &k, &m)
	n = 2 * k
	pairs := make([]Pair, m)
	for i in 0..<m {
		x0, x1 : int
		y0, y1 : u8
		libc.scanf("%d%c %d%c", &x0, &y0, &x1, &y1)
		x0 *= 2
		x1 *= 2
		if y0 == 'h' do x0 += 1
		if y1 == 'h' do x1 += 1
		pairs[i] = Pair{fst=x0, snd=x1}
	}
	if twosat(pairs) && ans[0] {
		for x, i in ans {
			if i == 0 do continue
			fmt.printf("%d%c", i, 'w' if x else 'h')
			if i != k - 1 do fmt.print(' ')
		}
		fmt.print('\n')
	} else do fmt.println("bad luck")
}
