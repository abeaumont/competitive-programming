import os
import strconv

// array sorting seems broken in V, let's do a simple shuffle sort
fn sort(mut xs [][]int) { // fixed arrays are also broken :shrug:
	for {
		mut ok := true
		for i in 1 .. xs.len {
			if xs[i - 1][0] > xs[i][0]
				|| (xs[i - 1][0] == xs[i][0] && xs[i - 1][1] > xs[i][1])
				|| (xs[i - 1][0] == xs[i][0] && xs[i - 1][1] == xs[i][1] && xs[i - 1][2] > xs[i][2]) {
				xs[i - 1], xs[i] = xs[i], xs[i - 1]
				ok = false
			}
		}
		if ok {
			break
		}
	}
}

const base_orientations = [
	'x,y,z',
	'x,-z,y',
	'x,-y,-z',
	'x,z,-y',
	'-x,-y,z',
	'-x,-z,-y',
	'-x,y,-z',
	'-x,z,y',
]

fn all_orientations() [][][]int {
	n := base_orientations.len
	mut orientations := [][][]int{len: n * 3}
	for i, o in base_orientations {
		orientations[i] = [][]int{len: 3}
		for j, c in o.split(',') {
			mut sign := 1
			if c.len == 2 {
				sign = -1
			}
			v := match c[c.len - 1..] {
				'x' { 0 }
				'y' { 1 }
				'z' { 2 }
				else { panic('invalid' + c) }
			}
			orientations[i][j] = [v, sign]
		}
	}
	for i in 1 .. 3 {
		for j in 0 .. n {
			orientations[n * i + j] = [][]int{len: 3}
			for k in 0 .. 3 {
				orientations[n * i + j][k] = orientations[n * (i - 1) + j][(k + 1) % 3]
			}
		}
	}
	return orientations
}

fn normalize(xs [][]int, orientation [][]int) [][]int {
	mut ys := [][]int{len: xs.len}
	for i, x in xs {
		ys[i] = []int{len: 3}
		for j, c in x {
			o := orientation[j]
			ys[i][o[0]] = c * o[1]
		}
	}
	return ys
}

fn coords(xs [][]int, ys [][]int) ?[]int {
	mut locs := [][]int{}
	for _, x in xs {
		for _, y in ys {
			locs << [x[0] - y[0], x[1] - y[1], x[2] - y[2]]
		}
	}
	sort(mut locs)
	mut c := 1
	for i in 1 .. locs.len {
		if locs[i] == locs[i - 1] {
			c++
		} else {
			c = 1
		}
		if c == 12 {
			return locs[i]
		}
	}
	return none
}

fn locate(xs [][]int, ys [][]int, orientation [][]int, orientations [][][]int) ([]int, [][]int, bool) {
	for _, o in orientations {
		if location := coords(normalize(xs, orientation), normalize(ys, o)) {
			return location, o, true
		}
	}
	return []int{}, [][]int{}, false
}

fn parse_scanner() [][]int {
	mut scanner := [][]int{}
	for line := os.get_line(); line != ''; line = os.get_line() {
		tokens := line.split(',').map(fn (tok string) int {
			return strconv.atoi(tok) or { 0 }
		})
		scanner << [tokens[0], tokens[1], tokens[2]]
	}
	return scanner
}

fn count(scanners [][][]int, locations [][]int, orientations [][][]int) int {
	mut beacons := [][]int{}
	n := scanners.len
	for i in 0 .. n {
		for _, loc in normalize(scanners[i], orientations[i]) {
			beacons << [
				loc[0] + locations[i][0],
				loc[1] + locations[i][1],
				loc[2] + locations[i][2],
			]
		}
	}
	sort(mut beacons)
	mut c := 1
	for i in 1 .. beacons.len {
		if beacons[i] != beacons[i - 1] {
			c++
		}
	}
	return c
}

fn main() {
	mut scanners := [][][]int{}
	for os.get_line() != '' {
		scanners << parse_scanner()
	}
	n := scanners.len
	all := all_orientations()

	mut locations := [][]int{len: n}
	mut orientations := [][][]int{len: n}
	mut set := []bool{len: n, init: false}
	mut queue := []int{cap: n}
	locations[0] = [0, 0, 0]
	orientations[0] = [[0, 1], [1, 1], [2, 1]]
	set[0] = true
	queue << 0
	for queue.len > 0 {
		i := queue.pop()
		for j := 0; j < n; j++ {
			if set[j] {
				continue
			}
			location, o, found := locate(scanners[i], scanners[j], orientations[i], all)
			if found {
				locations[j] = [
					location[0] + locations[i][0],
					location[1] + locations[i][1],
					location[2] + locations[i][2],
				]
				orientations[j] = o
				set[j] = true
				queue << j
			}
		}
	}
	println(count(scanners, locations, orientations))
}
