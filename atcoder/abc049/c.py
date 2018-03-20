#!/usr/bin/python3
# https://abc049.contest.atcoder.jp/tasks/arc065_a
s = input()
i = 0
while True:
	if i == len(s):
		print('YES')
		break
	if len(s) - i < 5:
		print('NO')
		break
	if s[i] == 'd':
		if s[i:i+5] != 'dream':
			print('NO')
			break
		if len(s) - i < 7:
			i += 5
			continue
		if s[i:i+7] != 'dreamer':
			i += 5
			continue
		if len(s) - i == 7 or s[i+7] != 'a':
			i += 7
			continue
		i += 5
		continue
	if s[i] == 'e':
		if s[i:i+5] != 'erase':
			print('NO')
			break
		if len(s) - i < 6:
			i += 5
			continue
		if s[i:i+6] != 'eraser':
			i += 5
			continue
		if len(s) - i == 6 or s[i+6] != 'a':
			i += 6
			continue
		i += 5
		continue
	print('NO')
	break
