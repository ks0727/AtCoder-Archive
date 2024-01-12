N = int(input())

one = ['H','D','C','S']
two = ['A','2','3','4', '5', '6', '7', '8', '9', 'T', 'J', 'Q','K']

def ok(s):
    if(s[0] not in one):
        return False
    if(s[1] not in two):
        return False
    return True

ss = []
ans = True
for _ in range(N):
    s = input()
    if(s in ss):
        ans = False
    if ok(s) == False:
        ans = False
    ss.append(s)

if ans :
    print("Yes")
else:
    print("No")