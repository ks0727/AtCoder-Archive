n = int(input())
s = input()
if len(s)%2 == 0:
    print("No")
    exit()

for i in range((len(s)+1)//2-1):
    if s[i] != '1':
        print("No")
        exit()

if s[(len(s)+1)//2-1] != '/':
    print("No")
    exit()

for i in range((len(s)+1)//2,n):
    if(s[i] != '2'):
        print("No")
        exit()

print("Yes")