def main():
    h,w,x,y = map(int,input().split())
    s = [input() for _ in range(h)]
    t = input()
    visited = [[False]*w for _ in range(h)]
    x -= 1
    y -= 1
    visited[x][y] = True
    for c in t:
        nx,ny = x,y
        if c == 'U':
            nx -= 1
        elif c == 'D':
            nx += 1
        elif c == 'L':
            ny -= 1
        elif c == 'R':
            ny += 1
        if nx < 0 or ny < 0 or nx >= h or ny >= w:
            continue
        if s[nx][ny] == '#':
            continue
        visited[nx][ny] = True
        x = nx; y = ny
    
    ans = 0
    for i in range(h):
        for j in range(w):
            if visited[i][j] and s[i][j] == '@':
                ans += 1
    
    print(x+1,y+1,ans)

if __name__ == "__main__":
    main()