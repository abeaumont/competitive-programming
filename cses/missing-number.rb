n,*x=$<.read.split.map(&:to_i)
puts n * (n+1)/2 - x.inject(:+)
