n,q = map(int,input().split())
cards = [0 for _ in range(n)]
for _ in range(q):
    tp,x = map(int,input().split())
    x -= 1
    if tp == 1:
        cards[x]+=1
    elif tp == 2:
        cards[x]+=2
    else:
        if cards[x] >= 2:
            print("Yes")
        else:
            print("No")