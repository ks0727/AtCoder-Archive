n,l,r = map(int,input().split())
a = [i+1 for i in range(n)]
ans = a[0:l]+reversed(a[l:r])+a[r:n]
print(ans)