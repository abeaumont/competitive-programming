package main

import (
	"bufio"
	"container/heap"
	"os"
	"sort"
)

type unit struct {
	team byte
	hp   int
}

type status struct {
	hp int
	p  int
}

type loc struct {
	d int
	p int
}

type pq []*loc

func (q pq) Len() int { return len(q) }
func (q pq) Less(i, j int) bool {
	if q[i].d < q[j].d {
		return true
	}
	if q[i].d == q[j].d {
		return q[i].p < q[j].p
	}
	return false
}
func (q pq) Swap(i, j int) { q[i], q[j] = q[j], q[i] }
func (q *pq) Push(x interface{}) {
	*q = append(*q, x.(*loc))
}
func (q *pq) Pop() interface{} {
	old := *q
	l := len(old)
	x := old[l-1]
	*q = old[:l-1]
	return x
}

func run(w [][]byte, ep int) (int, bool) {
	n, m, ng, ne, c := len(w), len(w[0]), 0, 0, 0
	xs := map[int]unit{}
	for i, r := range w {
		for j, e := range r {
			if e == 'E' {
				xs[i*m+j] = unit{e, 200}
				ne += 1
			} else if e == 'G' {
				xs[i*m+j] = unit{e, 200}
				ng += 1
			}
		}
	}
	for {
		used := map[int]bool{}
		keys := []int{}
		for k := range xs {
			keys = append(keys, k)
		}
		sort.Ints(keys)
		nc := false
		for _, k := range keys {
			if ng == 0 {
				nc = true
				break
			}
			e, ok := xs[k]
			if !ok {
				continue
			}
			_, ok = used[k]
			if ok {
				continue
			}
			y, x := k/m, k%m
			s := make([][]bool, n)
			for i := 0; i < n; i++ {
				s[i] = make([]bool, m)
			}
			s[y][x] = true
			q := &pq{&loc{0, k}}
			heap.Init(q)
			var t byte
			if e.team == 'E' {
				t = 'G'
			} else {
				t = 'E'
			}
			var d, i, j int
			for {
				if q.Len() == 0 {
					d = 0
					break
				}
				l := heap.Pop(q).(*loc)
				var p int
				d, p = l.d, l.p
				i, j = p/m, p%m
				if w[i-1][j] == t || w[i+1][j] == t || w[i][j+1] == t || w[i][j-1] == t {
					if w[i-1][j] == t {
						i -= 1
					} else if w[i][j+1] == t {
						j += 1
					} else if w[i][j-1] == t {
						j -= 1
					} else {
						i += 1
					}
					d += 1
					break
				}
				if !s[i-1][j] {
					s[i-1][j] = true
					if w[i-1][j] == '.' {
						heap.Push(q, &loc{d + 1, (i-1)*m + j})
					}
				}
				if !s[i+1][j] {
					s[i+1][j] = true
					if w[i+1][j] == '.' {
						heap.Push(q, &loc{d + 1, (i+1)*m + j})
					}
				}
				if !s[i][j-1] {
					s[i][j-1] = true
					if w[i][j-1] == '.' {
						heap.Push(q, &loc{d + 1, i*m + (j - 1)})
					}
				}
				if !s[i][j+1] {
					s[i][j+1] = true
					if w[i][j+1] == '.' {
						heap.Push(q, &loc{d + 1, i*m + (j + 1)})
					}
				}
			}
			if d > 1 {
				q := &pq{&loc{0, i*m + j}}
				heap.Init(q)
				v := make([][]int, n)
				for i := 0; i < n; i++ {
					v[i] = make([]int, m)
					for j := 0; j < m; j++ {
						v[i][j] = n*m + 1
					}
				}
				s := make([][]bool, n)
				for i := 0; i < n; i++ {
					s[i] = make([]bool, m)
				}
				for {
					l := heap.Pop(q).(*loc)
					var p int
					d, p = l.d, l.p
					i, j = p/m, p%m
					s[i][j] = true
					if p == k {
						break
					}
					if w[i][j] != '.' && d > 0 {
						continue
					}
					v[i][j] = d
					if !s[i-1][j] {
						s[i-1][j] = true
						if w[i-1][j] != '#' {
							heap.Push(q, &loc{d + 1, (i-1)*m + j})
						}
					}
					if !s[i+1][j] {
						s[i+1][j] = true
						if w[i+1][j] != '#' {
							heap.Push(q, &loc{d + 1, (i+1)*m + j})
						}
					}
					if !s[i][j-1] {
						s[i][j-1] = true
						if w[i][j-1] != '#' {
							heap.Push(q, &loc{d + 1, i*m + (j - 1)})
						}
					}
					if !s[i][j+1] {
						s[i][j+1] = true
						if w[i][j+1] != '#' {
							heap.Push(q, &loc{d + 1, i*m + (j + 1)})
						}
					}
				}
				d -= 1
				if v[i-1][j] == d {
					i -= 1
				} else if v[i][j-1] == d {
					j -= 1
				} else if v[i][j+1] == d {
					j += 1
				} else {
					i += 1
				}
				delete(xs, k)
				xs[i*m+j] = e
				w[y][x] = '.'
				w[i][j] = e.team
				used[i*m+j] = true
				y, x = i, j
			}
			ts := []status{}
			if k := (y-1)*m + x; w[y-1][x] == t {
				ts = append(ts, status{xs[k].hp, k})
			}
			if k := (y+1)*m + x; w[y+1][x] == t {
				ts = append(ts, status{xs[k].hp, k})
			}
			if k := y*m + (x - 1); w[y][x-1] == t {
				ts = append(ts, status{xs[k].hp, k})
			}
			if k := y*m + (x + 1); w[y][x+1] == t {
				ts = append(ts, status{xs[k].hp, k})
			}
			sort.Slice(ts, func(i, j int) bool {
				if ts[i].hp < ts[j].hp {
					return true
				}
				if ts[i].hp == ts[j].hp {
					return ts[i].p < ts[j].p
				}
				return false
			})
			if len(ts) > 0 {
				p := ts[0].p
				u := xs[p]
				delete(xs, p)
				if u.team == 'G' {
					u.hp -= ep
				} else {
					u.hp -= 3
				}
				if u.hp > 0 {
					xs[p] = u
				} else {
					if u.team == 'E' {
						return 0, false
					} else {
						ng -= 1
					}
					w[p/m][p%m] = '.'
				}
			}
		}
		if !nc {
			c += 1
		}
		if ng == 0 {
			break
		}
	}
	s := 0
	for _, u := range xs {
		s += u.hp
	}
	return c * s, true
}

func main() {
	w := [][]byte{}
	r := bufio.NewReader(os.Stdin)
	for {
		l, err := r.ReadBytes('\n')
		if err != nil {
			w = append(w, l[:len(l)])
			break
		}
		w = append(w, l[:len(l)-1])
	}
	ep := 4
	for {
		n := len(w)
		wc := make([][]byte, n)
		for i := 0; i < n; i++ {
			m := len(w[i])
			wc[i] = make([]byte, m)
			copy(wc[i], w[i])
		}
		if c, ok := run(wc, ep); ok {
			println(c)
			break
		}
		ep += 1
	}
}
