h,w = map(int,input().split())
a = [[int(x) for x in input().split()] for _ in range(h)]

for i in range(h):
    ansi = ""
    for j in range(w):
        if a[i][j] == 0:
            ansi += '.'
        else:
            c = ord('A')+(a[i][j]-1)
            ansi += chr(c)
    print(ansi)