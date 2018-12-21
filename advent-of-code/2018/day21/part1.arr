fun idiv(a :: NumInteger, b :: NumInteger) -> NumInteger:
  num-floor(a / b)
where:
  idiv(4, 4) is 1
  idiv(4, 3) is 1
  idiv(3, 4) is 0
end

fun iter(a, b):
  if (b > 0):
    iter(num-modulo((a + num-modulo(b, 256)) * 65899, 16777216), idiv(b, 256))
  else:
    a
  end
end

print(iter(10704114, 65536))
