s = input()
t = ""
for i in range(len(s)):
    if i % 2 == 0:
        t += s[i+1]
        t += s[i]

print(t)