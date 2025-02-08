def main():
    n,m = map(int,input().split())
    s = [list(input()) for _ in range(n)]
    t = [list(input()) for _ in range(m)]
    
    for i in range(n-m+1):
        for j in range(n-m+1):
            ok = True
            for ii in  range(m):
                if not ok:
                    break
                for jj in range(m):
                    if s[i+ii][j+jj] != t[ii][jj]:
                        ok = False
                        break
                    if ii == m-1 and jj == m-1:
                        print(i+1,j+1)
                        exit(0)

if __name__ == "__main__":
    main()