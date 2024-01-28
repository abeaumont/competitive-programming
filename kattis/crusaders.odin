// https://open.kattis.com/problems/crusaders
package main

import "core:c/libc"
import "core:fmt"
import "core:slice"

main :: proc() {
	c, a : int
	libc.scanf("%d %d", &c, &a)
	cs := make([]int, c)
	as := make([]int, a)
	for i in 0..<a do libc.scanf("%d", &as[i])
	ps := make([]int, a)
	budget := 1500
	for i in 0..<a {
		v := as[i]
		start := 0
		end := c
		for j := 1; j * 8192 < c; j += 1 {
			k := j * 8192
			if cs[k] == 0 {
				budget -= 1
				assert(budget >= 0)
				fmt.printf("Q %d\n", k+1)
				libc.scanf("%d", &cs[k])
			}
			if v >= cs[k] do start = k
			else {
				end = k
				break
			}
		}
		if v == cs[start] do ps[i] = start + 1
		else {
			loop: for b := (end - start) / 2; b >= 1 ; b /= 2 {
				for ;start + b < end; {
					if cs[start+b] == 0 {
						budget -= 1
						assert(budget >= 0)
						fmt.printf("Q %d\n", start+b+1)
						libc.scanf("%d", &cs[start+b])
					}
					if v == cs[start+b] {
						start += b
						break loop
					}
					if v > cs[start+b] do start += b
					else do break
				}
			}
			ps[i] = start + 1
		}
	}
	fmt.print("A ")
	for i in 0..<a do fmt.printf("%d ", ps[i])
	fmt.print('\n')
}
