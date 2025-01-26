def main():
    h,w = map(int,input().split())
    s = [input() for _ in range(h)]
    
    l = w
    r = 0
    t = h
    d = 0
    
    for i in range(h):
        for j in range(w):
            if s[i][j] == '#':
                l = min(l,j)
                r = max(r,j)
                t = min(t,i)
                d = max(d,i)
                
    for i in range(t,d+1):
        for j in range(l,r+1):
            if s[i][j] == '.':
                print("No")
                return
    
    print("Yes")

if __name__ == "__main__":
    main()