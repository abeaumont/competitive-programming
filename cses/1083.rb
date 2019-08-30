#!/usr/bin/env ruby
# https://cses.fi/problemset/task/1083
n,*x=$<.read.split.map(&:to_i)
puts n * (n+1)/2 - x.inject(:+)
