import io/FileReader
import structs/ArrayList
import text/Regexp
import text/StringTokenizer

addr: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] + r[b] }
addi: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] + b }
mulr: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] * r[b] }
muli: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] * b }
banr: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] & r[b] }
bani: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] & b }
borr: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] | r[b] }
bori: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] | b }
setr: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] }
seti: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { a }
gtir: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { a > r[b] ? 1 : 0 }
gtri: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] > b ? 1 : 0 }
gtrr: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] > r[b] ? 1 : 0 }
eqir: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { a == r[b] ? 1 : 0 }
eqri: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] == b ? 1 : 0 }
eqrr: func (a: Int, b: Int, c: Int, r: ArrayList<Int>) -> Int { r[a] == r[b] ? 1 : 0 }

input := FileReader new(stdin)
t := 0
while (true) {
    l := input readLine()
    if (l empty?()) break
    pb := Regexp compile("Before: \\[([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+)]")
    b := ArrayList<Int> new()
    for ((i, group) in pb matches(l))
        if (i) b add(group toInt())
    op := Int[4] new()
    for ((i, n) in input readLine() split(" ")) op[i] = n toInt()
    pa := Regexp compile("After:  \\[([0-9]+), ([0-9]+), ([0-9]+), ([0-9]+)]")
    a := ArrayList<Int> new()
    for ((i, group) in pa matches(input readLine()))
        if (i) a add(group toInt())
    input readLine()
    fs := [
        addr, addi, mulr, muli, banr, bani, borr, bori, setr, seti, gtir, gtri,
        gtrr, eqir, eqri, eqrr
    ] as ArrayList<Func(Int, Int, Int, ArrayList<Int>) -> Int>
    c := 0
    for (f in fs)
        if (a[op[3]] == f(op[1], op[2], op[3], b))
            c += 1
    if (c >= 3) t += 1
}
"#{t}" println()
