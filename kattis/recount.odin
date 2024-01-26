// https://open.kattis.com/problems/recount
package main

import "core:fmt"
import "core:os"
import "core:strings"

@(optimization_mode="speed")
main :: proc() {
	m := make(map[string]int)
	data, ok := os.read_entire_file_from_handle(os.stdin)
	it := string(data)
	for x in strings.split_lines_iterator(&it) {
		if x == "***" do break
		c, ok := &m[x]
		if ok do c^ += 1
		else do m[x] = 1
	}
	best := 0
	draw := false
	winner : string
	for k, v in m {
		if v > best {
			best = v
			draw = false
			winner = k
		} else if v == best do draw = true
	}
	if draw do fmt.println("Runoff!")
	else do fmt.println(winner)
}
