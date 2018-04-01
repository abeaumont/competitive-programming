# https://www.hackerrank.com/challenges/ruby-tutorial-each
def scoring(array)
  array.each { |user| user.update_score() }
end
