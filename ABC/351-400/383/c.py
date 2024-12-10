import heapq
di = [1,0,-1,0]
dj = [0,-1,0,1]

def main():
    h,w,d = map(int,input().split())
    s = [input() for _ in range(h)]
    
    q = []
    heapq.heapify(q)
    grid = []
    for i in range(h):
        a = []
        for j in range(w):
            a.append(-1)
        grid.append(a)
        

    for i in range(h):
        for j in range(w):
            if s[i][j] == 'H':
                heapq.heappush(q,(-d,i,j))
                grid[i][j] = d

    while len(q) > 0:
        c,i,j = heapq.heappop(q)
        c *= -1
        for v in range(4):
            ni = i + di[v]
            nj = j + dj[v]
            if ni < 0 or nj < 0 or ni >= h or nj >= w:
                continue
            if s[ni][nj] == '#':
                continue
            
            if grid[ni][nj] < c-1:
                grid[ni][nj] = c-1
                heapq.heappush(q,(-c+1,ni,nj))
    ans = 0
    for i in range(h):
        for j in range(w):
            if grid[i][j] >= 0:
                ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()