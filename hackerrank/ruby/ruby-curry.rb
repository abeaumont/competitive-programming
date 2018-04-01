# https://www.hackerrank.com/challenges/ruby-curry
power_function = -> (x, z) {
  (x) ** z
}

base = gets.to_i
raise_to_power = power_function.curry.(base)

power = gets.to_i
puts raise_to_power.(power)
