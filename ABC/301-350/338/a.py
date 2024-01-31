import re

s = input()
pattern = "^[A-Z][a-z]*$"
if(re.match(pattern,s)):
    print('Yes')
else:
    print('No')
    