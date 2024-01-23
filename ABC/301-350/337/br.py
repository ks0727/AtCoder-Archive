import re

s = input()
if re.match("^A*B*C*$",s):
    print("Yes")
else:
    print("No")
