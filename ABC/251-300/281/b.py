import re

s = input()
pattern = "[A-Z][1-9][0-9]{5}[A-Z]"
if re.match(pattern,s):
    print("Yes")
else:
    print("No")