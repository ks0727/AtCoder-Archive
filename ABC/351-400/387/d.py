from collections import deque

def main():
    h,w = map(int,input().split())
    s = [input() for _ in range(h)]
    
    q = deque()
    q.append((0,0,0))
    q.append((0,0,1))
    INF = 1001001001
    
    vdist = [[INF]*w for _ in range(h)]
    hdist = [[INF]*w for _ in range(h)]
    
    di = [1,1,-1,-1]
    dj = [1,-1,1,-1]
    vdist[0][0] = 0
    hdist[0][0] = 0
    while len(q) > 0:
        i,j,k = q.popleft()
        if k == 0:
            ni = i
            nj = j+1
            if nj >= w or s[i][nj] == '#':
                continue
            vdist[i][nj] = hdist[i][j]+1
            q.append((i,nj,k^1))
            
            nj = j-1
            if nj < 0:
                continue
            
            vdist[i][nj] = hdist[i][j]+1
            q.append((i,nj,k^1))
        else:
            ni = i+1
            nj = j
            if ni >= h:
                continue
            hdist[ni][j] = vdist[i][j]+1
            q.append((ni,j,k^1))
            
            ni = i-1
            if ni < 0:
                continue
            
            hdist[ni][j] = vdist[i][j]+1
            q.append((ni,j,k^1))
    ans = min(hdist)

if __name__ == "__main__":
    main()