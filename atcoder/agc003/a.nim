# https://agc003.contest.atcoder.jp/tasks/agc003_a
var s: set[char]
for c in stdin.readLine:
  s.incl(c)
if ('N' in s) == ('S' in s) and ('E' in s) == ('W' in s): echo "Yes"
else: echo "No"
