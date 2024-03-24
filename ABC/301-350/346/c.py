n,k = map(int,input().split())
a = list(map(int,input().split()))

ans = k*(k+1)//2
st = set()
for i in range(n):
    if a[i] <= k and a[i] not in st:
        ans -= a[i]
    st.add(a[i])

print(ans)
        