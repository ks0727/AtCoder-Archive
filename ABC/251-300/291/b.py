n = int(input())
x = list(map(int,input().split()))
x = sorted(x)
nx = x[n:-n]
ans = sum(nx)/len(nx)
print(f'{ans:.10f}')