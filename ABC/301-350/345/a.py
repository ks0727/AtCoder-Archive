import re

s = input()
pattern = "^<=*>$"
if(re.match(pattern,s)):print("Yes")
else:print("No")
