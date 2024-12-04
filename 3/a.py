import re
import sys

mul_regex = r'mul\((\d+),(\d+)\)'

_sum = 0
matches = re.findall(mul_regex, sys.stdin.read())
for match in matches:
  a, b = match
  _sum += int(a) * int(b)


print(_sum)
