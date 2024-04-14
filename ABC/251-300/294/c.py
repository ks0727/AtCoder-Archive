n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

aidx,bidx = 0,0
for i in range(n+m):
    if aidx == n:
        b[bidx] = i+1
        bidx+= 1
        continue
    if bidx == m:
        a[aidx] = i+1
        aidx+=1
        continue
    if a[aidx] < b[bidx]:
        a[aidx] = i+1
        aidx+=1
    else:
        b[bidx] = i+1
        bidx+=1

a = [str(x) for x in a]
b = [str(x) for x in b]
a = " ".join(a)
b = " ".join(b) 
print(a)
print(b)