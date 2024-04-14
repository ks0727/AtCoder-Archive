n,q = map(int,input().split())
yet = set(list(range(1,n+1)))
for _ in range(q):
    qi = list(map(int,input().split()))
    if qi[0] == 1:
        pass
    elif qi[0] == 2:
        yet.discard(qi[1])
    else:
        person = next(iter(yet))
        print(person)

