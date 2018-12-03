#!/usr/bin/env ruby
m = Array.new(1000)
m.fill { Array.new(1000, 0) }
while (l = gets)
  /#\d+ @ (?<x>\d+),(?<y>\d+): (?<w>\d+)x(?<h>\d+)/ =~ l
  x1, y1 = x.to_i, y.to_i
  x2, y2 = x1 + w.to_i, y1 + h.to_i
  (y1...y2).each { |i| (x1...x2).each { |j| m[i][j] += 1 } }
end
puts m.inject(0) { |s, x| s + x.inject(0) { |t, y| t + (y > 1 ? 1 : 0) } }
