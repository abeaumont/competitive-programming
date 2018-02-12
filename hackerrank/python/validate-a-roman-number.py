# https://www.hackerrank.com/challenges/validate-a-roman-number
regex_pattern = r'M{0,3}((C(D|M))|D?C{0,3})((X(L|C))|L?X{0,3})((I(V|X))|(V?I{0,3}))$'
import re
print(str(bool(re.match(regex_pattern, raw_input()))))
