#!/usr/bin/env python3
# https://abc062.contest.atcoder.jp/tasks/arc074_a
def s(a1, a2, a3): return max([a1, a2, a3]) - min([a1, a2, a3])

h, w = map(int, input().split())
h1 = h // 3
h2 = (h - h1) // 2
h3 = h - h1 - h2
t = s(h1 * w, h2 * w, h3 * w)
w1 = w // 3
w2 = (w - w1) // 2
w3 = w - w1 - w2
t = min(t, s(h * w1, h * w2, h * w3))
w1 = w // 3
w2 = w - w1
h1 = h // 2
h2 = h - h1
t = min(t, s(h * w1, h1 * w2, h2 * w2))
w1 = (w // 3) + 1
w2 = w - w1
t = min(t, s(h * w1, h1 * w2, h2 * w2))
h1 = h // 3
h2 = h - h1
w1 = w // 2
w2 = w - w1
t = min(t, s(h1 * w, h2 * w1, h2 * w2))
h1 = h // 3 + 1
h2 = h - h1
t = min(t, s(h1 * w, h2 * w1, h2 * w2))
print(t)
