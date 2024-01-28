// https://open.kattis.com/problems/compoundwords
package main

import "core:fmt"
import "core:os"
import "core:slice"
import "core:strings"

main :: proc() {
	data, _ := os.read_entire_file_from_handle(os.stdin)
	it := string(data)
	words : [dynamic]string
	for x in strings.split_multi_iterate(&it, []string{"\n", " "}) {
		if x != "" do append(&words, x)
	}
	xs : [dynamic]string
	for i in 0..<len(words) {
		for j in i+1..<len(words) {
			append(&xs, strings.concatenate([]string{words[i], words[j]}))
			append(&xs, strings.concatenate([]string{words[j], words[i]}))
		}
	}
	ys := make([]string, len(xs))
	for i in 0..<len(xs) do ys[i] = xs[i][:]
	slice.sort(ys)
	fmt.println(ys[0])
	for i in 1..<len(ys) do if ys[i] != ys[i-1] do fmt.println(ys[i])
}
