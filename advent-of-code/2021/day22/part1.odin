package main

import "core:fmt"
import "core:bufio"
import "core:io"
import "core:os"
import "core:strconv"
import "core:strings"

main :: proc() {
  buf : [100000]byte
  n, err := os.read(os.stdin, buf[:])
  assert(err == os.ERROR_NONE)
  cube : [101][101][101]bool
  for line in strings.split(string(buf[:n]), "\n") {
    if line == "" {
      continue
    }
    action, _, ranges := strings.partition(line, " ")
    coords := strings.split(ranges, ",")
    _, _, cx := strings.partition(coords[0], "=")
    _, _, cy := strings.partition(coords[1], "=")
    _, _, cz := strings.partition(coords[2], "=")
    sx0, _, sx1 := strings.partition(cx, "..")
    sy0, _, sy1 := strings.partition(cy, "..")
    sz0, _, sz1 := strings.partition(cz, "..")
    x0, ok0 := strconv.parse_int(sx0); assert(ok0)
    x1, ok1 := strconv.parse_int(sx1); assert(ok1)
    y0, ok2 := strconv.parse_int(sy0); assert(ok2)
    y1, ok3 := strconv.parse_int(sy1); assert(ok3)
    z0, ok4 := strconv.parse_int(sz0); assert(ok4)
    z1, ok5 := strconv.parse_int(sz1); assert(ok5)
    if x0 < -50 || x1 > 50 || y0 < -50 || y1 > 50 || z0 < -50 || z0 > 50 {
      continue
    }
    for i := x0; i <= x1; i += 1 {
      for j := y0; j <= y1; j += 1 {
        for k := z0; k <= z1; k += 1 {
          cube[i+50][j+50][k+50] = action == "on"
        }
      }
    }
  }
  c := 0
  for i := 0; i <= 100; i += 1 {
    for j := 0; j <= 100; j += 1 {
      for k := 0; k <= 100; k += 1 {
        if cube[i][j][k] { c += 1 }
      }
    }
  }
  fmt.println(c)
}
