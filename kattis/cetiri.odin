// https://open.kattis.com/problems/cetiri
package main

import "core:c/libc"
import "core:fmt"
import "core:slice"

main :: proc() {
	x : [3]int
	libc.scanf("%d %d %d", &x[0], &x[1], &x[2])
	slice.sort(x[:])
	switch {
	case x[1] - x[0] == x[2] - x[1]:
		fmt.println(2 * x[2] - x[1])
	case x[1] - x[0] > x[2] - x[1]:
		fmt.println(x[0] + x[2] - x[1])
	case:
		fmt.println(2 * x[1] - x[0])
	}
}
	
