w,b = map(int,input().split())

s = "wbwbwwbwbwbw"
nw = w//7
nb = b//5
p = min(nw,nb)
w -= p*7
b -= p*5
ans = False
for i in range(12):
    cw = w
    cb = b
    now = 0
    while cw > 0 or cb > 0:
        idx = (now+i)%12
        if s[idx] == 'w':
            if cw > 0: cw-=1
            else : break
        if s[idx] == 'b':
            if cb > 0 :cb -= 1
            else : break
        now+=1
    if cw == 0 and cb == 0:
        ans = True
if ans:
    print("Yes")
else:
    print("No")
        

