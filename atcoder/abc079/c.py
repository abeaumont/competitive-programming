#!/usr/bin/env python3
# https://abc079.contest.atcoder.jp/tasks/abc079_c
a, b, c, d = map(int, input())
if a + b + c + d == 7: print('{}+{}+{}+{}=7'.format(a, b, c, d))
elif a + b + c - d== 7: print('{}+{}+{}-{}=7'.format(a, b, c, d))
elif a + b - c + d == 7: print('{}+{}-{}+{}=7'.format(a, b, c, d))
elif a + b - c - d == 7: print('{}+{}-{}-{}=7'.format(a, b, c, d))
elif a - b + c + d == 7: print('{}-{}+{}+{}=7'.format(a, b, c, d))
elif a - b + c - d == 7: print('{}-{}+{}-{}=7'.format(a, b, c, d))
elif a - b - c + d == 7: print('{}-{}-{}+{}=7'.format(a, b, c, d))
elif a - b - c - d == 7: print('{}-{}-{}-{}=7'.format(a, b, c, d))
