s = input()
n = len(s)
if n%2 == 1:
    print("No")
    exit()

used = [False]*26
for i in range(n//2):
    if used[ord(s[2*i])-ord('a')]:
        print("No")
        exit()
        
    if s[2*i] != s[2*i+1]:
        print("No")
        exit()
    
    used[ord(s[2*i])-ord('a')] = True

print("Yes")