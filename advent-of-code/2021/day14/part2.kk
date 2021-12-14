import std/core
import std/os/readline

fun parse(line : string): <exn> (string, char)
  match line.split(" -> ")
    [s1, s2] -> match s2.list
      [c] -> (s1, c)
      _ -> throw("invalid insertion character")
    _ -> throw("invalid rule", ExnError)

fun readlines() : <console, div> list<(string, char)>
  try-default([], fn() Cons(readline().parse, readlines()))

fun dup(pair : (string, int), c : char) : list<(string, int)>
  match pair.fst.list
    [c1, c2] -> [([c1, c].string, pair.snd), ([c, c2].string, pair.snd)]
    _ -> []

fun dups(rules : list<(string, char)>, pair : (string, int)) : list<(string, int)>
  match rules
    Cons((s, c), _) | s == pair.fst -> dup(pair, c)
    Cons(_, tail) -> tail.dups(pair)
    _ -> []

fun assoc(xs : list<string>) : list<(string, int)>
  match xs
    [] -> []
    Cons(hd, tl) -> Cons((hd, 1), tl.assoc)

fun pairs(s : sslice) : <div> list<string>
  if s.count < 2 then [] else Cons(s.string, s.advance(1).pairs)

fun pairs(s : string) : <div> list<string> s.first(2).pairs

fun merge(xs : list<(string, int)>) : <div> list<(string, int)>
  match xs
    [] -> []
    [x] -> [x]
    Cons((pr1, v1), Cons((pr2, v2), tl2)) | pr1 == pr2 ->
      match merge(Cons((pr2, v2), tl2))
        Cons((pr, v), tl) -> Cons((pr, v1 + v), tl)
        _ -> []
    Cons(x, tl) -> Cons(x, tl.merge)

fun insert(xs : list<(string, int)>, x : (string, int)) : list<(string, int)>
  match xs
    [] -> [x]
    Cons(y, _) | x.fst < y.fst -> Cons(x, xs)
    Cons(y, tl) -> Cons(y, tl.insert(x))

fun sort(xs : list<(string, int)>) : list<(string, int)>
  match xs
    [] -> []
    Cons(hd, tl) -> tl.sort.insert(hd)

fun dups(xs : list<(string, int)>) : list<list<(string, int)>>
  match xs
    [] -> []
    Cons((s, v), tl) -> Cons(s.list.map(fn(c) (c.string, v)), tl.dups)

fun main()
  val s = readline()
  val start = s.head
  val end = s.last.string
  var ps := s.pairs.assoc
  readline()
  val rules = readlines()
  repeat(40)
    ps := ps.map(fn(key){ rules.dups(key) }).concat.sort.merge
  ps := ps.dups.concat.sort.merge.map(fn((p, v)) if p == start then (p, v + 1) else (p, v))
  val ans = ps.map(fn((p, v)) if p == end then (v + 1)/2 else v/2)
  println(ans.maximum - ans.minimum)
