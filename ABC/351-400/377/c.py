def main():
    di = [2,1,-1,-2,-2,-1,1,2]
    dj = [1,2,2,1,-1,-2,-2,-1]
    ps = set()
    n,m = map(int,input().split())
    for _ in range(m):
        a,b = map(int,input().split())
        a-=1
        b-=1
        ps.add((a,b))
        for d in range(8):
            na = a+di[d]
            nb = b+dj[d]
            if na < 0 or nb < 0 or na >= n or nb >= n:
                continue
            ps.add((na,nb))
    
    ans = n**2
    ans -= len(ps)
    print(ans)
        

if __name__ == "__main__":
    main()