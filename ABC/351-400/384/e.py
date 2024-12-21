import heapq

def main():
    q = []
    heapq.heapify(q)
    h,w,x = map(int,input().split())
    si,sj = map(int,input().split())
    si -= 1; sj -= 1
    s = [list(map(int,input().split())) for _ in range(h)]
    di = [1,0,-1,0]
    dj = [0,-1,0,1]
    visited = [[False]*w for _ in range(h)]
    bombed = [[False]*w for _ in range(h)]
    now = s[si][sj]
    bombed[si][sj] = True
    heapq.heappush(q,(now,si,sj))
    while len(q) != 0:
        c,i,j = heapq.heappop(q)
        if not bombed[i][j] and s[i][j] < now/x:
            bombed[i][j] = True
            now += s[i][j]
        if not(i==si and j==sj) and not bombed[i][j]:
            break
        for d in range(4):
            ni = i + di[d]
            nj = j + dj[d]
            if ni < 0 or nj < 0 or ni >= h or nj >= w:
                continue
            if bombed[ni][nj] or visited[ni][nj]:
                continue
            heapq.heappush(q,(s[ni][nj],ni,nj))
            visited[ni][nj] = True
    
    print(now)


if __name__ == "__main__":
    main()