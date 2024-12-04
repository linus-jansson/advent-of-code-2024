import re
import sys
def compute_enabled_multiplications(input_string):
  pattern = r"mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\)"
  total = 0
  enabled = True
  for match in re.finditer(pattern, input_string):
      instruction = match.group(0)
      if instruction == 'do()':
          enabled = True
      elif instruction == "don't()":
          enabled = False
      else:
          if enabled:
            total += int(match.group(1)) * int(match.group(2))
  return total

if __name__ == "__main__":
  result = compute_enabled_multiplications(sys.stdin.read())
  print(result)
