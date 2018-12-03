#!/usr/bin/env ruby
m = Array.new(1000)
m.fill { Array.new(1000, 0) }
c = Array.new
while (l = gets)
  /#(?<id>\d+) @ (?<x>\d+),(?<y>\d+): (?<w>\d+)x(?<h>\d+)/ =~ l
  x1, y1 = x.to_i, y.to_i
  x2, y2 = x1 + w.to_i, y1 + h.to_i
  c.push([x1, y1, x2, y2, id])
end
c.each { |x1, y1, x2, y2| (y1...y2).each{ |i| (x1...x2).each{ |j| m[i][j] += 1 } } }
c.each do |x1, y1, x2, y2, id|
  if (y1...y2).all? { |i| (x1...x2).all? { |j| m[i][j] <= 1 } }
    puts id
    break
  end
end
