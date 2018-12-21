fun idiv(a :: NumInteger, b :: NumInteger) -> NumInteger:
  num-floor(a / b)
where:
  idiv(4, 4) is 1
  idiv(4, 3) is 1
  idiv(3, 4) is 0
end

fun is-even(n :: NumInteger) -> Boolean:
  num-modulo(n, 2) == 0
where:
  is-even(6) is true
  is-even(3) is false
end

fun set-bit16(a :: NumInteger) -> NumInteger:
  n = 65536
  if (a < n) or is-even(idiv(a, n)):
    a + n
  else:
    a
  end
where:
  set-bit16(0) is 65536
  set-bit16(65536) is 65536
  set-bit16(42) is 65578
  set-bit16(12420065) is 12420065
end

fun iter(a, b):
  if (b > 0):
    iter(num-modulo((a + num-modulo(b, 256)) * 65899, 16777216), idiv(b, 256))
  else:
    a
  end
end

fun loop(x, t):
  n = iter(10704114, set-bit16(x))
  if t.member(n):
    x
  else:
    loop(n, t.add(n))
  end
end

print(loop(0, empty-tree-set))
