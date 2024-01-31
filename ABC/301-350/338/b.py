s = input()

a = [0 for _ in range(26)]
for c in s:
    a[ord(c)-ord('a')]+=1

mx = -1
for i in range(26):
    if(a[i] > mx):
        mx = a[i]

idx = 0
for i in range(26):
    if(a[i] == mx):
        idx = i
        break

print(chr(ord('a')+idx))