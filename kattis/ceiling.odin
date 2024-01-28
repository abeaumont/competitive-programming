// https://open.kattis.com/problems/ceiling
package main

import "core:c/libc"
import "core:fmt"
import "core:slice"

Node :: struct {
	v: int,
	l: ^Node,
	r: ^Node,
}

N :: 50
trees : [N]^Node
hashes : [N][dynamic]u8

insert :: proc(n: ^Node, v: int) -> ^Node {
	if n == nil {
		node := new(Node)
		node.v = v
		return node
	}
	if v < n.v do n.l = insert(n.l, v)
	else do n.r = insert(n.r, v)
	return n
}

traverse :: proc(n: ^Node, h: ^[dynamic]u8) {
	h := h
	if n.l != nil {
		append(h, 'l')
		traverse(n.l, h)
	}
	if n.r != nil {
		append(h, 'r')
		traverse(n.r, h)
	}
	append(h, 'u')
}

main :: proc() {
	n, k : int
	libc.scanf("%d %d", &n, &k)
	for i in 0..<n {
		for j in 0..<k {
			x : int
			libc.scanf("%d", &x)
			trees[i] = insert(trees[i], x)
		}
		traverse(trees[i], &hashes[i])
	}
	strings := make([]string, n)
	for i in 0..<n do strings[i] = string(hashes[i][:])
	slice.sort(strings)
	c := 1
	for i in 1..<n do if strings[i-1] != strings[i] do c += 1
	fmt.println(c)
}
