#!/usr/bin/env wren
import "io" for Stdin

var c = 0
var a = Stdin.readLine()
while (a != "") {
  c = c + Num.fromString(a)
  a = Stdin.readLine()
}
System.print(c)
