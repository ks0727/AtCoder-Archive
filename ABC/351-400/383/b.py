def main():
    h,w,d = map(int,input().split())
    s = [input() for _ in range(h)]
    ans = 0
    for i1 in range(h):
        for j1 in range(w):
            for i2 in range(h):
                for j2 in range(w):
                    if i1 == i2 and j1 == j2:
                        continue
                    
                    if s[i1][j1] == '#' or s[i2][j2] == '#':
                        continue
                    
                    cnt = 0
                    for i in range(h):
                        for j in range(w):
                            if s[i][j] != '.':
                                continue
                            if abs(i-i1) + abs(j-j1) <= d or abs(i-i2) + abs(j-j2)<=d:
                                cnt += 1
                    
                    ans = max(ans,cnt)
    
    print(ans)
    

if __name__ == "__main__":
    main()