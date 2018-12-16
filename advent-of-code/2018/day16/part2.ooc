import io/FileReader
import structs/ArrayList
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
while (true) {
    if (!input readLine() empty?()) continue
    if (!input readLine() empty?()) continue
    break
}
input readLine()
r := [0,0,0,0] as ArrayList<Int>
while (true) {
    l := input readLine()
    if (l length() <= 1) break
    op := Int[4] new()
    for ((i, n) in l split(" ")) op[i] = n toInt()
    fs := [
        eqir, addi, gtir, setr, mulr, seti, muli, eqri, bori, bani
        gtrr, eqrr, addr, gtri, borr, banr
    ] as ArrayList<Func(Int, Int, Int, ArrayList<Int>) -> Int>
    r[op[3]] = fs[op[0]](op[1], op[2], op[3], r)
}
"#{r[0]}" println()
