package main

import "core:fmt"
import "core:bufio"
import "core:io"
import "core:os"
import "core:slice"
import "core:strconv"
import "core:strings"

Action :: struct {
  on: bool,
  x0, x1, y0, y1, z0, z1: int,
}

main :: proc() {
  buf : [100000]byte
  n, err := os.read(os.stdin, buf[:])
  assert(err == os.ERROR_NONE)
  as : [dynamic]Action
  xs, ys, zs : [dynamic]int
  append(&xs, 0, 200000)
  append(&ys, 0, 200000)
  append(&zs, 0, 200000)
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
    x0 += 100000; x1 += 100000
    y0 += 100000; y1 += 100000
    z0 += 100000; z1 += 100000
    append(&xs, x0, x1 + 1)
    append(&ys, y0, y1 + 1)
    append(&zs, z0, z1 + 1)
    append(&as, Action{action == "on", x0, x1, y0, y1, z0, z1})
  }
  slice.sort(xs[:])
  slice.sort(ys[:])
  slice.sort(zs[:])
  sum : i64 = 0
  for i := 1; i < len(xs); i += 1 {
    fmt.println(i)
    if xs[i] == xs[i-1] {
      continue
    }
    for j := 1; j < len(ys); j += 1 {
      if ys[j] == ys[j-1] {
        continue
      }
      for k := 1; k < len(zs); k += 1 {
        if zs[k] == zs[k-1] {
          continue
        }
        x, y, z := xs[i-1], ys[j-1], zs[k-1]
        on := false
        for a in as {
          if x >= a.x0 && x <= a.x1 && y >= a.y0 && y <= a.y1 && z >= a.z0 && z <= a.z1 {
            on = a.on
          }
        }
        if on {
          sum += i64(xs[i]-xs[i-1]) * i64(ys[j]-ys[j-1]) * i64(zs[k]-zs[k-1])
        }
      }
    }
  }
  fmt.println(sum)
}
