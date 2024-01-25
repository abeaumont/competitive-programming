// https://open.kattis.com/problems/basicprogramming1
package main

import "core:c/libc"
import "core:fmt"
import "core:slice"

main :: proc() {
	N :: 200_000
	n, t : int
	libc.scanf("%d %d", &n, &t)
	x : [N]int
	for i in 0..<n {
		libc.scanf("%d", &x[i])
	}
	switch t {
	case 1:
		fmt.println(7)
	case 2:
		switch {
		case x[0] > x[1]:
			fmt.println("Bigger")
		case x[0] == x[1]:
			fmt.println("Equal")
		case:
			fmt.println("Smaller")
		}
	case 3:
		slice.sort(x[:3])
		fmt.println(x[1])
	case 4:
		sum := 0
		for i in 0..<n {
			sum += x[i]
		}
		fmt.println(sum)
	case 5:
		sum := 0
		for i in 0..<n {
			if x[i] & 1 == 0 {
				sum += x[i]
			}
		}
		fmt.println(sum)
	case 6:
		for i in 0..<n {
			c := x[i] % 26 + 'a'
			fmt.printf("%c", c)
		}
		fmt.println()
	case 7:
		i := 0
		for {
			if x[i] < 0 {
				fmt.println("Cyclic")
				break
			}
			j := x[i]
			x[i] = -1
			i = j
			if i >= n {
				fmt.println("Out")
				break
			}
			if i == n -1 {
				fmt.println("Done")
				break
			}
		}
	}
}
