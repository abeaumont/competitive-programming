# https://www.hackerrank.com/challenges/ruby-tutorial-unless
def scoring(array)
  array.each { |u| u.update_score unless u.is_admin? }
end
