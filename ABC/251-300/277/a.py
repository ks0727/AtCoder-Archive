n,x = map(int,input().split())
p = list(map(int,input().split()))

for i in range(len(p)):
    if(p[i] == x):
        print(i+1)
        break

