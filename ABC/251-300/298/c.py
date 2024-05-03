from collections import defaultdict

n = int(input())
q = int(input())

box = defaultdict(list)
ball = defaultdict(set)

for _ in range(q):
    query = list(map(int,input().split()))
    if query[0] == 1:
        i,j = query[1],query[2]
        i -= 1
        j -= 1
        box[j].append(i)
        ball[i].add(j)
    elif query[0] == 2:
        i = query[1]
        i -= 1
        arr = sorted(box[i])
        s = [str(x+1) for x in arr]
        s = " ".join(s)
        print(s)
    else:
        i = query[1]
        i -= 1
        arr = sorted(ball[i])
        s = [str(x+1) for x in arr]
        s = " ".join(s)
        print(s)