#!/usr/bin/env wren
import "io" for Stdin

var xs = List.new()
var a = Stdin.readLine()
while (a != "") {
  xs.add(Num.fromString(a))
  a = Stdin.readLine()
}

var i = 0
var c = 0
var m = {}
while (true) {
  c = c + xs[i % xs.count]
  if (m.containsKey(c)) {
    System.print(c)
    break
  }
  m[c] = true
  i = i + 1
}
