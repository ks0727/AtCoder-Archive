h,w = map(int,input().split())
a = [[int(x) for x in input().split()] for _ in range(h)]

visited = [[False for _ in range(w)] for _ in range(h)]
visited[0][0] = True

di = [1,0]
dj = [0,1]

ans = 0
def dfs(v: tuple, st : set)->None:
    i,j = v
    visited[i][j] = True
    if i == h-1 and j == w-1:
        global ans
        ans += 1
        return
    for d in range(2):
        ni = i+di[d]
        nj = j+dj[d]
        if ni < 0 or nj < 0 or ni >= h or nj >= w:
            continue
        if visited[ni][nj]:
            continue
        if a[ni][nj] in st:
            continue
        st.add(a[ni][nj])
        dfs((ni,nj),st)
        visited[ni][nj] = False
        st.discard(a[ni][nj])
        
st = set()
st.add(a[0][0])
dfs((0,0),st)
print(ans)
        
