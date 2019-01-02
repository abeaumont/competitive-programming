loop 1 = 1
loop 2 = 2
loop n | even n = loop (n - 1) * 2
loop n = loop (n - 1) * 2 + 1

iter 0 = return ()
iter t = do
  n <- readLn
  print (loop n)
  iter (t - 1)

main = do
  t <- readLn
  iter t
